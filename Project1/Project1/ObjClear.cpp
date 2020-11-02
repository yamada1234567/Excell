//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjClear::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjClear::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉړ�����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStage2());
		m_key_flag = true;
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"1�X�e�[�W�N���A�I", 260, 225, 32, c);
	Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);
						        //y���W(���E) , x���W(�㉺) , �T�C�Y
}