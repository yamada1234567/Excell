
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "Oxygen.h"
#include "GameL\HitBoxManager.h"

using namespace GameL;
CObjOxygen::CObjOxygen(float x, float y)
{
	m_x = x;
	m_y = y;
}

void CObjOxygen::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM,OBJ_OXYGEN, 1);
}

void CObjOxygen::Action()
{
	
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

	m_vx *= 3.0f;
	m_vy *= 1.5f;

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

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}
}

void CObjOxygen::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 30.0f;
	src.m_bottom = 28.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left =  32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(7, &src, &dst, c, 0.0f);
}