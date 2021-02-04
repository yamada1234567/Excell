
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "BomBullet.h"
#include "GameL\HitBoxManager.h"


using namespace GameL;


CObjBomBullet::CObjBomBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}


void CObjBomBullet::Init()
{
	m_vx = 0.0f;


	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_BOM_BULLET, 1);
}


void CObjBomBullet::Action()
{
	m_y += -12.0f;

	m_x += m_vx;


	if (m_x < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}


	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);



	
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);


		CObjBom* obj_b = new CObjBom(m_x, m_y);
		Objs::InsertObj(obj_b, OBJ_BOM, 1);

		return;
	}
}


void CObjBomBullet::Draw()
{
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 45.0f;
	src.m_bottom = 45.0f;


	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	
	Draw::Draw(24, &src, &dst, c, 0.0f);
}