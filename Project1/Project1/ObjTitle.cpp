
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjTitle.h"


using namespace GameL;


void CObjTitle::Init()
{
	m_key_flag = false;
}


void CObjTitle::Action()
{

	if (Input::GetVKey(VK_RETURN)==true)
	{
		if (m_key_flag==true)
		{
			Scene::SetScene(new CSceneDes());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
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

	Draw::Draw(1, &src, &dst, c, 0.0f);
}