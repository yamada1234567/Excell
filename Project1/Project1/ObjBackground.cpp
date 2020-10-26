//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjBackground.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	m_y2 = -800.0f;
}
//アクション
void CObjBackground::Action()
{
	//背景１の動作
	m_y1 -= 10.0f;
	if (m_y1 <-800.0f)
		m_y1 = 800;

	//背景２の動作
	m_y2 -= 10.0f;
	if (m_y2 <-800.0f)
		m_y2 = 800;
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

	//表示位置背景１
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_y1;
	dst.m_right = 800.0f + m_y1;
	dst.m_bottom = 600.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//表示位置背景２
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_y2;
	dst.m_right = 800.0f + m_y2;
	dst.m_bottom = 600.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);
}