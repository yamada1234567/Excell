#pragma once
//使用するヘッダー
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoL.h"
#include "GameL\HitBoxManager.h"
//使用するネームスペース
using namespace GameL;
CObjmeteoL::CObjmeteoL(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjmeteoL::Init()
{
	m_hp = 5;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time=0;
	m_left_bottom = 96.0f;//表示位置
	m_top_right   = 0.0f; //表示位置

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 96, 96, ELEMENT_ENEMY, OBJ_meteoL, 1);
}
//アクション
void CObjmeteoL::Action()
{
	
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
	m_vx *= 0.5f;
	m_vy *= 0.5f;

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

	//bomにあったら消滅
	if (hit->CheckObjNameHit(OBJ_BOM) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//ダメージ判定
	if (hit->CheckElementHit(ELEMENT_BULLET) == true)
	{
		m_hp -= 1;
		if (0>=m_hp)
		{
			int item;

			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//アイテム　作成中
			srand(time(NULL));
			item = rand() % 20;//倒した際に出るランダムな数値の数
				if (item == 1)//そのランダムに出た数値が特定の数値の場合アイテムを出す
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 2)
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 3)
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 4)
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 5)
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 6)
				{
					CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
				}
				if (item == 7)
				{
					CObjitem* obj_item = new CObjitem(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_item, OBJ_ITEM, 5);
				}
				if (item == 8)
				{
					CObjitem* obj_item = new CObjitem(m_x + 3.0f, m_y);
	                Objs::InsertObj(obj_item, OBJ_ITEM, 5);
				}
				if (item == 9)
				{
					CObjshield* obj_b = new CObjshield(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_SHIELD, 1);
				}
		}
	}

	m_time++;


	//敵回転
	if (m_time >= 25)
	{
		m_top_right = 96.0f;
		m_left_bottom = 0.0f;


		if (m_time >= 50)
		{
			m_time = 0;

		}

	}
	else
	{
		m_top_right = 0.0f;
		m_left_bottom = 96.0f;

	}

}
//ドロー
void CObjmeteoL::Draw()
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
	dst.m_top = m_top_right + m_y;
	dst.m_left = m_left_bottom + m_x;
	dst.m_right = m_top_right + m_x;
	dst.m_bottom = m_left_bottom + m_y;
	//画像登録
	Draw::Draw(2, &src, &dst, c, 0.0f);
}
void CObjmeteoL::SetVector(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}