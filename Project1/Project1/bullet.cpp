//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "bullet.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	m_vx = 0.0f;

	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, -40, ELEMENT_PLAYER, OBJ_BULLET, 1);
}

//�A�N�V����
void CObjBullet::Action()
{
	m_y += -5.0f;

	m_x += m_vx;

	//�̈�O�ɏo����폜
	if (m_x > 800.f)
	{
		this->SetStatus(false);
	}
	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
}

//�h���[
void CObjBullet::Draw()
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
	dst.m_top = -40.0f+m_y;
	dst.m_left = 0.0f+m_x;
	dst.m_right =32.0f+m_x;
	dst.m_bottom = 0.0f+m_y;

	//1�Ԃɓo�^�����O���t�B�b�N���̏������Ƃɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}