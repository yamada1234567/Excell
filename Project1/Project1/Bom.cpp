//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Bom.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBom::CObjBom(float x, float y)
{
	m_x = x-80;
	m_y = y-80;
	m_time=0;

	si_x=200;//x�T�C�Y
	si_y=200;//y�T�C�Y
}

//�C�j�V�����C�Y
void CObjBom::Init()
{
	m_vx = 0.0f;

	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, si_x, si_y, ELEMENT_BULLET, OBJ_BOM, 1);
}

//�A�N�V����
void CObjBom::Action()
{
	m_time++;

	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (m_time==5)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}



}

//�h���[
void CObjBom::Draw()
{
	//�`�ʃJ���[��� R=RED G=Green B=Blue A=alpha
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = si_x + m_x;
	dst.m_bottom = si_y + m_y;

	//1�Ԃɓo�^�����O���t�B�b�N���̏������Ƃɕ`��
	Draw::Draw(50, &src, &dst, c, 0.0f);
}