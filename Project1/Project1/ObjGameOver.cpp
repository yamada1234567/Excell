//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
//#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

CObjGameOver::CObjGameOver(int c)
{
	SG=c;

}

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ

}

//アクション
void CObjGameOver::Action()
{
	////エンターキーを押してシーン：titleに移動する
	//if (Input::GetVKey(VK_RETURN) == true)
	//{
	//	Scene::SetScene(new CSceneTitle());
	//}
	//else
	//{
	//	m_key_flag = true;
	//}

	if (SG == 1)
	{		
		//エンターキーを押してシーン：次のステージに移動する
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
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 325, 200, 32, c);
	Font::StrDraw(L"GAME OVER", 320, 250, 32, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 200, 350, 32, c);
											//y座標(左右) , x座標(上下) , サイズ
}