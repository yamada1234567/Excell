//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameHead.h"
#include "heroima.h"
#include "UtilityModule.h"

#include "GameL/DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjHeroime::CObjHeroime()
{

}

//イニシャライズ
void CObjHeroime::Init()
{


}

//アクション
void CObjHeroime::Action()
{



}


//ドロー
void CObjHeroime::Draw()
{

	//描画カラー情報　R＝Red G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top = 0.0f ;
	dst.m_left = 0.0f ;
	dst.m_right = 36.0f ;
	dst.m_bottom = 36.0f ;

	Draw::Draw(15, &src, &dst, c, 0.0f);
}
//600*800