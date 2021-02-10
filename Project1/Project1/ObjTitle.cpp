
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "ObjDes.h"


using namespace GameL;


void CObjTitle::Init()
{
	m_key_flag = false;
	m_key_flag1 = false;
}


void CObjTitle::Action()
{

	if (Input::GetVKey(VK_RETURN)==true)
	{
		m_key_flag = true;
	}

	if (m_key_flag == true)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			
			if (m_key_flag1 == true)
			{

				Scene::SetScene(new CSceneMain());

			}

		}
		else
		{
			m_key_flag1 = true;
		}
	}



}


void CObjTitle::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 780.0f;
	src.m_bottom = 600.0f;

	dst.m_top = 0;
	dst.m_left = 0;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;


	if (m_key_flag == true)
	{	
		Draw::Draw(2, &src, &dst, c, 0.0f);
	}
	else
	{
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
}