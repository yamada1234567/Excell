//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackground::Init()
{
	m_y1 = 0.0f;
	m_y2 = -800.0f;
}
//�A�N�V����
void CObjBackground::Action()
{
	//�w�i�P�̓���
	m_y1 -= 10.0f;
	if (m_y1 <-800.0f)
		m_y1 = 800;

	//�w�i�Q�̓���
	m_y2 -= 10.0f;
	if (m_y2 <-800.0f)
		m_y2 = 800;
}
//�h���[
void CObjBackground::Draw()
{
	//�`��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ݒ�
	src.m_top = 264.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 448.0f;

	//�\���ʒu�w�i�P
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_y1;
	dst.m_right = 800.0f + m_y1;
	dst.m_bottom = 600.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�\���ʒu�w�i�Q
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_y2;
	dst.m_right = 800.0f + m_y2;
	dst.m_bottom = 600.0f;
	Draw::Draw(5, &src, &dst, c, 0.0f);
}