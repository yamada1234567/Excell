
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"bossima.h"


using namespace GameL;


CObjBossima::CObjBossima(float x, float y)
{


	m_x = x;
	m_y = y;

}


void CObjBossima::Init()
{
	m_time = 0;

}

void CObjBossima::Action()
{
	m_time++;

	if (m_time==20)
	{
		this->SetStatus(false);
	}
}

void CObjBossima::Draw()
{
	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top =100.0f;
	src.m_left = 150.0f;
	src.m_right = 650.0f;
	src.m_bottom = 520.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 620.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 480.0f + m_y;

	
	Draw::Draw(50, &src, &dst, c, 0.0f);


}