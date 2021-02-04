#pragma once
//�g�p����w�b�_�[
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "Alien.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjAlien::CObjAlien(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjAlien::Init()
{

	m_hp = 1;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;
	m_left_bottom =50.0f;//�\���ʒu
	m_top_right = 0.0f; //�\���ʒu

	item = 0;

	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_ENEMY, OBJ_Alien, 1);
}

//�A�N�V����
void CObjAlien::Action()
{
	m_time++;
		
	//�ړ�����
	m_vx = 1.0f;
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

	//����
	m_vx *= 3.5f;
	m_vy *= 0.0f;

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
	}
	if (m_y < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_x < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (m_x > 800.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//��l���ɓ������������
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		return;
	}

	//bom�ɂ����������
	if (hit->CheckObjNameHit(OBJ_BOM) != nullptr)
	{
		m_hp = 0;

		//���ˉ���炷
		Audio::Start(3);
	}


	//�_���[�W����
	if (hit->CheckElementHit(ELEMENT_BULLET) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{

			//�G��������炷
			Audio::Start(3);
			
			//����
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
	


		}

		srand(time(NULL));
		item = rand() % 2;//�A�C�e�����o��m��
		
		if(item == 1)
		{ 
			CObjshield* obj_b = new CObjshield(m_x + 3.0f, m_y);
			Objs::InsertObj(obj_b, OBJ_SHIELD, 1);
		}
		else
		{
			CObjBomb* obj_b = new CObjBomb(m_x + 3.0f, m_y);
			Objs::InsertObj(obj_b, OBJ_BOMB, 1);
		}
		
		return;
	}



}

//�h���[
void CObjAlien::Draw()
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
	dst.m_left = 50.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 50.0f + m_y;


	//覐Γo�^
	Draw::Draw(20, &src, &dst, c, 0.0f);

}