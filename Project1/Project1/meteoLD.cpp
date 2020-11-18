#pragma once
//�g�p����w�b�_�[
#include <stdlib.h>
#include <time.h>
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoLD.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjmeteoLD::CObjmeteoLD(float x, float y)
{
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjmeteoLD::Init()
{
	m_hp = 1;
	m_vx = 0.0f;
	m_vy = -1.0f;
	m_time = 0;
	m_left_bottom = 32.0f;//�\���ʒu
	m_top_right = 0.0f; //�\���ʒu


	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_meteoRD, 1);
}
//�A�N�V����
void CObjmeteoLD::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 1.0f;

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
	m_vx *= 6.0f;
	m_vy *= 6.0f;

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

	//��l���ɓ������������
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//bom�ɂ����������
	if (hit->CheckObjNameHit(OBJ_BOM) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	/*�_���[�W����*/
	if (hit->CheckElementHit(ELEMENT_BULLET) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			int item;

			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//�A�C�e���@�쐬��
			srand(time(NULL));
			item = rand() % 30;//�|�����ۂɏo�郉���_���Ȑ��l�̐�
			if (item == 1)//���̃����_���ɏo�����l������̐��l�̏ꍇ�A�C�e�����o��
			{
				CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
			}
			if (item == 2)
			{
				CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
			}
			if (item == 3)
			{
				CObjOxygen* obj_b = new CObjOxygen(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_OXYGEN, 1);
			}


		}
	}

	if (hit->CheckElementHit(ELEMENT_EXPLOSION) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	m_time++;


	//�G��]
	if (m_time >= 25)
	{
		m_top_right = 32.0f;
		m_left_bottom = 0.0f;


		if (m_time >= 50)
		{
			m_time = 0;

		}

	}
	else
	{
		m_top_right = 0.0f;
		m_left_bottom = 32.0f;

	}





}
//�h���[
void CObjmeteoLD::Draw()
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
	dst.m_top = m_top_right + m_y;
	dst.m_left = m_left_bottom + m_x;
	dst.m_right = m_top_right + m_x;
	dst.m_bottom = m_left_bottom + m_y;
	//�����؂�ւ�
	if (0 >= m_hp)
	{


		m_vx = 0;
		m_vy = 0;

		Draw::Draw(50, &src, &dst, c, 0.0f);

		de_time++;



		if (de_time >= 10)
		{
			Hits::DeleteHitBox(this);
			this->SetStatus(false);

		}


	}
	else
	{
		//覐Γo�^
		Draw::Draw(2, &src, &dst, c, 0.0f);

	}
}
void CObjmeteoLD::SetVector(float vx, float vy)
{
	m_vx = vx;
	m_vy = vy;
}