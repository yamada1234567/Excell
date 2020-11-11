//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
//#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjGameOver::CObjGameOver(int c)
{
	SG=c;

}

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;//�L�[�t���O

}

//�A�N�V����
void CObjGameOver::Action()
{
	////�G���^�[�L�[�������ăV�[���Ftitle�Ɉړ�����
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
		//�G���^�[�L�[�������ăV�[���F���̃X�e�[�W�Ɉړ�����
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
		//�G���^�[�L�[�������ăV�[���F���̃X�e�[�W�Ɉړ�����
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

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 325, 200, 32, c);
	Font::StrDraw(L"GAME OVER", 320, 250, 32, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 200, 350, 32, c);
											//y���W(���E) , x���W(�㉺) , �T�C�Y
}