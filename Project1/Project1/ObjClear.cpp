//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawTexture.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjClear::CObjClear(int Cou)
{

	SG = Cou;

}


//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjClear::Action()
{

	if (SG==2)
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

//�h���[
void CObjClear::Draw()
{
	//�`��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	if (SG == 2)
	{
		Font::StrDraw(L"1�X�e�[�W�N���A�I", 260, 225, 32, c);
		Font::StrDraw(L"next 2�X�e�[�W :ENTER_KEY", 100, 270, 50, c);
	}
	else if (SG == 3)
	{
		Font::StrDraw(L"2�X�e�[�W�N���A�I", 260, 225, 32, c);
		Font::StrDraw(L"next 3�X�e�[�W :ENTER_KEY", 100, 275, 50, c);
	}
	else if (SG == 4)
	{
		Font::StrDraw(L"3�X�e�[�W�N���A�I", 260, 225, 32, c);
		Font::StrDraw(L"next 4�X�e�[�W :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 5)
	{
		Font::StrDraw(L"4�X�e�[�W�N���A�I", 260, 225, 32, c);
		Font::StrDraw(L"next 5�X�e�[�W :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 6)
	{
		Font::StrDraw(L"5�X�e�[�W�N���A�I", 260, 225, 32, c);
		Font::StrDraw(L"next 6�X�e�[�W :ENTER_KEY", 100, 275, 50, c);

	}
	else if (SG == 7)
	{

		RECT_F src;
		RECT_F dst;
		//�؂���ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 780.0f;
		src.m_bottom = 600.0f;
		//�\���ʒu
		dst.m_top = 0;
		dst.m_left = 0;
		dst.m_right = 800.0;
		dst.m_bottom = 600.0;

		Draw::Draw(1, &src, &dst, c, 0.0f);
	}


}