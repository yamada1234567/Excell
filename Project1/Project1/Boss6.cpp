
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Boss6.h"
#include"UtilityModule.h"
#include "GameL\Audio.h"


using namespace GameL;


CObjBoss6::CObjBoss6(float x, float y)
{

	
	m_x =0;
	m_y = y - 150;

}


void CObjBoss6::Init()
{
	m_hp = 30;
	m_vx = 0.0f;
	m_vy = 0.0f;

	
	Hits::SetHitBox(this, m_x, m_y, 800, 800, ELEMENT_ENEMY, OBJ_BOSS6, 13);
}

void CObjBoss6::Action()
{
	m_vy = 1.0f;

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
	m_vy *= 0.4f;

	m_x += m_vx;
	m_y += m_vy;

	
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			
			Scene::SetScene(new CSceneBossexp(7));

		}

	}
}

void CObjBoss6::Draw()
{
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 530.0f;
	src.m_bottom = 530.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 1000.0f + m_x;
	dst.m_right = -200.0f + m_x;
	dst.m_bottom = 800.0f + m_y;


	if (0 >= m_hp)
	{


		m_vx = 0;
		m_vy = 0;

		Draw::Draw(50, &src, &dst, c, 0.0f);

		de_time++;



		if (de_time >= 10)
		{

			Audio::Start(3);

			Hits::DeleteHitBox(this);
			this->SetStatus(false);

		}


	}

	Draw::Draw(13, &src, &dst, c, 0.0f);
}