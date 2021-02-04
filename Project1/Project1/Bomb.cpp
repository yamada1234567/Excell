//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "Bomb.h"
#include "GameL\HitBoxManager.h"
//使用するネームスペース
using namespace GameL;
CObjBomb::CObjBomb(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjBomb::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 28, 32, ELEMENT_ITEM, OBJ_BOMB, 1);

}
//アクション
void CObjBomb::Action()
{
	//移動方向
	m_vx = 0.0f;
	m_vy = 0.5f;
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}
	//加速
	m_vx *= 3.0f;
	m_vy *= 2.0f;

	m_x += m_vx;
	m_y += m_vy;

	//hitbox更新用ポインターの取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//領域外に出たら削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

}
//ドロー
void CObjBomb::Draw()
{
	//描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//切れ取り設定
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right	 = 35.0f;
	src.m_bottom = 43.0f;
	//表示位置
	dst.m_top	 = 0.0f  + m_y;
	dst.m_left 	 = 38.0f + m_x;
	dst.m_right  = 1.5f  + m_x;
	dst.m_bottom = 30.0f + m_y;
	//画像登録
	Draw::Draw(23, &src, &dst, c, 0.0f);
}