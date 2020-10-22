#pragma once
//�g�p����w�b�_�[
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoS.h"
#include "GameL\HitBoxManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�C�j�V�����C�Y
void CObjmeteoS::Init()
{
	m_x = 0;
	m_y = 0;
	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_meteoS, 1);
}
//�A�N�V����
void CObjmeteoS::Action()
{
	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	if (hit->CheckObjNameHit(OBJ_meteoS) != nullptr)
	{
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
	dst.m_top = 0.0f;
	dst.m_left = 32.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 32.0f;
	//�摜�o�^
	Draw::Draw(2, &src, &dst, c, 0.0f);
}