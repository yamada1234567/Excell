//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Bom.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBom::CObjBom(float x, float y)
{
	m_x = x-80;
	m_y = y-80;
	m_time=0;

	si_x=200;//xサイズ
	si_y=200;//yサイズ
}

//イニシャライズ
void CObjBom::Init()
{
	m_vx = 0.0f;

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, si_x, si_y, ELEMENT_BULLET, OBJ_BOM, 1);
}

//アクション
void CObjBom::Action()
{
	m_time++;

	//hitbox更新用ポインターの取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (m_time==5)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}



}

//ドロー
void CObjBom::Draw()
{
	//描写カラー情報 R=RED G=Green B=Blue A=alpha
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = si_x + m_x;
	dst.m_bottom = si_y + m_y;

	//1番に登録したグラフィックをの情報をもとに描画
	Draw::Draw(50, &src, &dst, c, 0.0f);
}