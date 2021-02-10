
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjDes.h"


using namespace GameL;


void CObjDes::Init()
{
	m_key_flag = false;
}


void CObjDes::Action()
{

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}


void CObjDes::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 680.0f;
	src.m_bottom = 480.0f;

	dst.m_top = 0;
	dst.m_left = 0;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}