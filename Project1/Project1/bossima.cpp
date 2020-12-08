//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"bossima.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBossima::CObjBossima(float x, float y)
{

	//表示位置
	m_x = x;
	m_y = y;

}

//イニシャライズ
void CObjBossima::Init()
{
	m_time = 0;

}
//アクション
void CObjBossima::Action()
{
	m_time++;

	if (m_time==20)
	{
		this->SetStatus(false);
	}
}
//ドロー
void CObjBossima::Draw()
{
	//描画カラー情報 R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切れ取り設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置
	dst.m_top = 0.0f + m_y;
	dst.m_left = 400.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 400.0f + m_y;

	//1番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(50, &src, &dst, c, 0.0f);


}