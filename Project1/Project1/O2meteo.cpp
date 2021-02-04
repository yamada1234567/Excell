
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "O2meteo.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"


using namespace GameL;

CObjO2meteo::CObjO2meteo(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjO2meteo::Init()
{
	m_hp = 1;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_left_bottom = 32.0f;
	m_top_right = 0.0f; 

	de_time = 0;


	
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_O2meteo, 1);
}

void CObjO2meteo::Action()
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


	m_vx *= 0.0f;
	m_vy *= 4.5f;

	m_x += m_vx;
	m_y += m_vy;


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


			CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
			Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);


		}
	}

	if (hit->CheckElementHit(ELEMENT_EXPLOSION) == true)
	{
		m_hp -= 10;


		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}









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


void CObjO2meteo::Draw()
{

	float c[4] = { 1.0f,10.0f,30.0f,1.0f };
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



		if (de_time >= 3)
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
void CObjO2meteo::SetVector(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}