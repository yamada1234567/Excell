//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"bossima.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBossima::CObjBossima(float x, float y)
{

	//�\���ʒu
	m_x = x;
	m_y = y;

}

//�C�j�V�����C�Y
void CObjBossima::Init()
{
	m_time = 0;

}
//�A�N�V����
void CObjBossima::Action()
{
	m_time++;

	if (m_time==20)
	{
		this->SetStatus(false);
	}
}
//�h���[
void CObjBossima::Draw()
{
	//�`��J���[��� R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu
	dst.m_top = 0.0f + m_y;
	dst.m_left = 400.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 400.0f + m_y;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(50, &src, &dst, c, 0.0f);


}