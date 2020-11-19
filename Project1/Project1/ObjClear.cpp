//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

CObjClear::CObjClear(int Cou)
{

	SG = Cou;

}


//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjClear::Action()
{

	if (SG==2)
	{
		//エンターキーを押してシーン：次のステージに移動する
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

//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (SG == 2)
	{
		Font::StrDraw(L"1ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);
	}
	else if (SG == 3)
	{
		Font::StrDraw(L"2ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);
	}
	else if (SG == 4)
	{
		Font::StrDraw(L"3ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);

	}
	else if (SG == 5)
	{
		Font::StrDraw(L"4ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);

	}
	else if (SG == 6)
	{
		Font::StrDraw(L"5ステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);

	}
	else if (SG == 7)
	{
		Font::StrDraw(L"ラストステージクリア！", 260, 225, 32, c);
		Font::StrDraw(L"おめでとう！", 225, 275, 50, c);

	}


}