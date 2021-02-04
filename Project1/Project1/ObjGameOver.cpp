
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"


using namespace GameL;

CObjGameOver::CObjGameOver(int c)
{
	SG=c;

}


void CObjGameOver::Init()
{
	m_key_flag = false;

}


void CObjGameOver::Action()
{

	if (SG == 1)
	{		
		
		if (Input::GetVKey(VK_RETURN) == true)
		{

			m_key_flag = true;

			Scene::SetScene(new CSceneMain());

		}
		else
		{

			m_key_flag = true;
		}

	}
	else if (SG == 2)
	{
		
		if (Input::GetVKey(VK_RETURN) == true)
		{

			m_key_flag = true;

			Scene::SetScene(new CSceneStage2());

		}
		else
		{

			m_key_flag = true;
		}

	}
	else if (SG == 3)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneStage3());
			m_key_flag = true;
		}
		else
		{

			m_key_flag = true;
		}

	}
	else if (SG == 4)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneStage4());
			m_key_flag = true;
		}
		else
		{

			m_key_flag = true;
		}

	}
	else if (SG == 5)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneStage5());
			m_key_flag = true;
		}
		else
		{

			m_key_flag = true;

		}

	}
	else if (SG == 6)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneLast());
			m_key_flag = true;
		}
		else
		{

			m_key_flag = true;
		}

	}
}


void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 225, 140, 80, c);
	Font::StrDraw(L"GAME OVER", 225, 250, 80, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 100, 380, 50, c);
											
}