#pragma once
//使用するヘッダー
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoS.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjmeteoS::CObjmeteoS(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjmeteoS::Init()
{
	m_hp = 1;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_left_bottom =32.0f;//表示位置
	m_top_right   =0.0f; //表示位置

	de_time=0;//画像切り替え時間
	

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_meteoS, 1);
}
//アクション
void CObjmeteoS::Action()
{
	m_time++;
		
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
	m_vy *= 4.5f;

	m_x += m_vx;
	m_y += m_vy;

	//hitbox更新用ポインターの取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x,m_y);

	//領域外に出たら削除
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	//主人公に当たったら消滅
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	//bomにあったら消滅
	if (hit->CheckObjNameHit(OBJ_BOM) != nullptr)
	{
		m_hp = 0;

		//発射音を鳴らす
		Audio::Start(3);
	}

	//ダメージ判定
	if (hit->CheckElementHit(ELEMENT_BULLET) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			int item;

			//敵爆発音を鳴らす
			Audio::Start(3);

			////アイテム　作成中
			srand(time(NULL));
			item = rand() % 30;//アイテムが出る確率
			
			if (item == 1|| item == 3|| item == 5|| item == 7)
			{
				CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
			}
			
		}
	}

	if (hit->CheckElementHit(ELEMENT_EXPLOSION) == true)
	{
		m_hp -= 10;


		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	
	//敵回転
	if (m_time>=25)
	{
		m_top_right   = 32.0f;
		m_left_bottom = 0.0f;
	
	
		if (m_time >=50)
		{
			m_time = 0;

		}

	}
	else
	{
		m_top_right   = 0.0f;
		m_left_bottom = 32.0f;

	}
	

}

//ドロー
void CObjmeteoS::Draw()
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
	dst.m_top	 = m_top_right  + m_y;
	dst.m_left   = m_left_bottom + m_x;
	dst.m_right  = m_top_right + m_x;
	dst.m_bottom = m_left_bottom+ m_y;
	
	//爆発切り替え
	if (0 >= m_hp)
	{					
	

		m_vx = 0;
		m_vy = 0;

		Draw::Draw(50, &src, &dst, c, 0.0f);

		de_time++;
		
			

		if(de_time >= 20)
		{
			//敵爆発音を鳴らす
			Audio::Start(3);

			Hits::DeleteHitBox(this);
			this->SetStatus(false);
			return;
		}


	}
	else
	{
		//隕石登録
		Draw::Draw(2, &src, &dst, c, 0.0f);

	}



}
void CObjmeteoS::SetVector(float vx, float vy)
{
	m_vx=vx;
	m_vy=vy;
}