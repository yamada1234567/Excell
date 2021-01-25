//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "Diffusion.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjDifBullet::CObjDifBullet(float x, float y, float r, float spe)
{
	m_x = x;
	m_y = y;
	m_r = r-1000;
	m_speed = spe;
}

//�C�j�V�����C�Y
void CObjDifBullet::Init()
{
	m_vx = cos(3.14f/180.0f*m_r);
	m_vy = sin(3.14f / 180.0f * m_r);
	
	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_DIFFUSION, 1);
}

//�A�N�V����
void CObjDifBullet::Action()
{
	m_x += m_vx * m_speed;
	m_y -= m_vy * m_speed;

	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	
	//�̈�O�ɏo����폜
	if (m_x < -32.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_y < -32.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}







	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		Audio::Start(3);//���e����炷

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjDifBullet::Draw()
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
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//1�Ԃɓo�^�����O���t�B�b�N���̏������Ƃɕ`��
	Draw::Draw(1, &src, &dst, c, m_r);
}