#pragma once
//使用するヘッダー
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "Alien.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjmeteoSin::CObjmeteoSin(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjAlien::Init()
{
	m_hp = 2;

	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_left_bottom = 32.0f;//表示位置
	m_top_right = 0.0f; //表示位置


	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_Alien, 1);
}
//アクション
void CObjAlien::Action()
{
	//角度加算
	m_r += 2.0f;

	//360°で初期値に戻す
	if (m_r >= 360.0f)
	{
		m_r += 0.0f;
	}

	//移動方向
	m_vx = -1.0f;
	m_vy = sin(3.14 / 180 * m_r);//???を求めてn_vyに入れる

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
	m_vx *= 0.0f;
	m_vy *= 6.0f;

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
	}

	//主人公に当たったら消滅
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//ダメージ判定
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			int item;

			this->SetStatus(false);
			Hits::DeleteHitBox(this);

		}
	}

	m_time++;


	//敵回転
	if (m_time >= 25)
	{
		m_top_right = 32.0f;
		m_left_bottom = 0.0f;


		if (m_time >= 50)
		{
			m_time = 0;

		}

	}
	else
	{
		m_top_right = 0.0f;
		m_left_bottom = 32.0f;

	}


}

//ドロー
void CObjAlien::Draw()
{
	//描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//切れ取り設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;
	//表示位置
	dst.m_top =0.0f + m_y;
	dst.m_left = 32.0f+ m_x;
	dst.m_right =0.0f+ m_x;
	dst.m_bottom = 32.0f+ m_y;
	//画像登録
	Draw::Draw(2, &src, &dst, c, 0.0f);
}

void CObjAlien::SetVector(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}