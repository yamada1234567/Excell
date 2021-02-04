
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawTexture.h"

#include "GameHead.h"
#include "ObjClear.h"


using namespace GameL;

CObjClear::CObjClear(int Cou)
{

	SG = Cou;

}



void CObjClear::Init()
{
	m_key_flag = false;
}


void CObjClear::Action()
{

	if (SG==2)
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
	else if (SG == 7)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = true;
		}
		else
		{

			m_key_flag = true;
		}

	}


}


void CObjClear::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	if (SG == 2)
	{
		Font::StrDraw(L"1ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next 2ステージ :ENTER_KEY", 100, 270, 50, c);
	}
	else if (SG == 3)
	{
		Font::StrDraw(L"2ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next 3ステージ :ENTER_KEY", 100, 275, 50, c);
	}
	else if (SG == 4)
	{
		Font::StrDraw(L"3ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next 4ステージ :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 5)
	{
		Font::StrDraw(L"4ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next 5ステージ :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 6)
	{
		Font::StrDraw(L"5ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next 6ステージ :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 7)
	{

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


}