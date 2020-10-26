//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground::Init()
{

}
//アクション
void CObjBackground::Action()
{
	
}
//ドロー
void CObjBackground::Draw()
{
	//描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切れ取り設定
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;
	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	//画像登録
	Draw::Draw(5, &src, &dst, c, 0.0f);
}