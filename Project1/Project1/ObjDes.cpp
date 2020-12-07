//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjDes.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjDes::Init()
{
	m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjDes::Action()
{
	//�G���^�[�L�[�������ăV�[���F�Q�[�����C���Ɉړ�����
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

//�h���[
void CObjDes::Draw()
{
	//�`��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//�؂���ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//�\���ʒu
	dst.m_top = 0;
	dst.m_left = 0;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}