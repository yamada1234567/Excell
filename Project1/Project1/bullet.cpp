
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "bullet.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"


using namespace GameL;


CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjBullet::Init()
{
	m_vx = 0.0f;


	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_BULLET, 1);
}


void CObjBullet::Action()
{
	m_y += -12.0f;

	m_x += m_vx;


	if (m_x <0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}



	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	


	
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		Audio::Start(3);

		this->SetStatus(false);     
		Hits::DeleteHitBox(this);   

		return;
	}
}

void CObjBullet::Draw()
{
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;


	dst.m_top = 0.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right =32.0f+m_x;
	dst.m_bottom =32.0f+m_y;

	
	Draw::Draw(1, &src, &dst, c, 0.0f);
}