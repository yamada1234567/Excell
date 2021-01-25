//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "item.h"
#include "GameL\HitBoxManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjitem::CObjitem(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjitem::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_ITEM, 1);
}

//�A�N�V����
void CObjitem::Action()
{
	//�ړ�����
	m_vx = 0.0f;
	m_vy = 0.5f;
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}
	//����
	m_vx *= 3.0f;
	m_vy *= 2.0f;

	m_x += m_vx;
	m_y += m_vy;

	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�̈�O�ɏo����폜
	if (m_y > 600.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	if (hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			return;
		}

	}
}

//�h���[
void CObjitem::Draw()
{
	//�`��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//�؂���ݒ�
	src.m_top	 = 0.0f;
	src.m_left	 = 0.0f;
	src.m_right  = 30.0f;
	src.m_bottom = 28.0f;
	//�\���ʒu
	dst.m_top	 = 0.0f  + m_y;
	dst.m_left   = 32.0f + m_x;
	dst.m_right  = 0.0f  + m_x;
	dst.m_bottom = 32.0f + m_y;
	//�摜�o�^
	Draw::Draw(3, &src, &dst, c, 0.0f);
}