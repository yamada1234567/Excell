#pragma once

#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoM.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"


using namespace GameL;
CObjmeteoM::CObjmeteoM(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjmeteoM::Init()
{
	m_hp = 3;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_left_bottom = 64.0f;
	m_top_right   = 0.0f; 

	de_time = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ENEMY, OBJ_meteoM, 1);
}

void CObjmeteoM::Action()
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

	if (m_hp > 0)
	{
		
		m_vx *= 0.0f;
		m_vy *= 2.5f;

		m_x += m_vx;
		m_y += m_vy;
	}

	
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);


	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
	

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	if (hit->CheckObjNameHit(OBJ_BOM) != nullptr)
	{
		m_hp = 0;


		Audio::Start(3);
	}


	if (hit->CheckElementHit(ELEMENT_BULLET) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			int item;


			Audio::Start(3);


			
			srand(time(NULL));
			item = rand() % 20;
			if (item == 1)
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
			if (item == 5)
			{
				CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
			}
			if (item == 6)
			{
				CObjshield* obj_b = new CObjshield(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_SHIELD, 1);
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

	m_time++;



	if (m_time >= 25)
	{
		m_top_right = 64.0f;
		m_left_bottom = 0.0f;


		if (m_time >= 50)
		{
			m_time = 0;

		}

	}
	else
	{
		m_top_right = 0.0f;
		m_left_bottom = 64.0f;

	}
}

void CObjmeteoM::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	dst.m_top = m_top_right + m_y;
	dst.m_left = m_left_bottom + m_x;
	dst.m_right = m_top_right + m_x;
	dst.m_bottom = m_left_bottom + m_y;

	if (0 >= m_hp)
	{


		m_vx = 0;
		m_vy = 0;

		Draw::Draw(50, &src, &dst, c, 0.0f);
		
		de_time++;



		if (de_time >= 12)
		{

	
			Audio::Start(3);

			Hits::DeleteHitBox(this);
			this->SetStatus(false);

			return;
		}


	}
	else
	{

		Draw::Draw(2, &src, &dst, c, 0.0f);

	}
}
void CObjmeteoM::SetVector(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}