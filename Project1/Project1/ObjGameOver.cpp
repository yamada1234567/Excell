//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

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

	Font::StrDraw(L"YOU LOST", 205, 150, 100, c);
	Font::StrDraw(L"GAME OVER", 175, 250, 100, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 200, 380, 32, c);
											//y座標(左右) , x座標(上下) , サイズ
}