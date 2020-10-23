#pragma once
//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoS.h"
#include "GameL\HitBoxManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
CObjmeteoS::CObjmeteoS(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjmeteoS::Init()
{
	/*m_health = 3;*/
	m_vx = 0.0f;
	m_vy = 0.0f;
	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_meteoS, 1);
}
//�A�N�V����
void CObjmeteoS::Action()
{
	//�ړ�����
	m_vx = 0.0f;
	m_vy = 0.0f;
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
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	m_x += m_vx;
	m_y += m_vy;

	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x,m_y);

	/*if (m_x < -32.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		/*m_health -= 1;
		if (0>=m_health)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}*/
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}
//�h���[
void CObjmeteoS::Draw()
{
	//�`��
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//�؂���ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;
	//�\���ʒu
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//�摜�o�^
	Draw::Draw(2, &src, &dst, c, 0.0f);
}