//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameHead.h"
#include "heroima.h"
#include "UtilityModule.h"

#include "GameL/DrawFont.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjHeroime::CObjHeroime()
{
	m_y = 500 - 16;
	m_x = (810 / 2) - 16;

}

//�C�j�V�����C�Y
void CObjHeroime::Init()
{


}

//�A�N�V����
void CObjHeroime::Action()
{



}


//�h���[
void CObjHeroime::Draw()
{

	//�`��J���[���@R��Red G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 36.0f + m_x;
	dst.m_bottom = 36.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//600*800