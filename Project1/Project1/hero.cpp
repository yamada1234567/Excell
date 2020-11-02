//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "hero.h"
#include "triplebullet.h"
#include "UtilityModule.h"
#include "triplebullet2.h"

#include "GameL/DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_y = 500-16;
	m_x = (810/2)-16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_f = true;
	m_hp = 3;
	m_o=10;
	m_time = 0;

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_x, m_y, 37, 38, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	m_time++;
	//Hitbox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

		//��l���@�̒e�۔���
		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
				//�e�ۃI�u�W�F�N�g�쐬
				CObjBullet* obj_b = new CObjBullet(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_BULLET, 1);

				m_f = false;

			}
		}
		else
		{
			m_f = true;
		}

	//����
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 5.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 5.0f;

	}
	if (Input::GetVKey(VK_UP)==true)
	{
		m_y -= 5.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += 5.0f;
	}

	//�ړ��x�N�g��������
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̕����Ƀx�N�g���̑��x������
	if (Input::GetVKey(VK_RIGHT)==true)
	{
		m_vx += 100.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx += 100.0f;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy += 5.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy += 5.0f;
	}

	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//r�����[�g�����߂�

	//�������O���ǂ������ׂ�
	if (r==0.0f)
	{
		;//�O�Ȃ炻�̂܂�
	}
	else
	{
		//���K��
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}



	//�͈͊O�ɍs���Ȃ�����
	if (m_x + 32.0f > 800.0f-5.0f)
	{
		m_x = 800.0f - 5.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f - 5.0f)
	{
		m_y = 600.0f - 5.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

	//Hitbox�̓��e���X�V
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);



	//�_���[�W����
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

		//��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
		Scene::SetScene((CScene*)new CSceneGameOver());

		}
		
	}

	if (m_time % 60 == 0)
	{
		m_o--;

		if (0 == m_o)
		{
			//this->SetStatus(false);
			//Hits::DeleteHitBox(this);

			////��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
			//Scene::SetScene((CScene*)new CSceneGameOver());

		}
	}

	if (hit->CheckObjNameHit(OBJ_OXYGEN) != nullptr)
	{
		m_o = 10;

	}

}


//�h���[
void CObjHero::Draw()
{
	//�`��J���[���@R��Red G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top		= 0.0f;
	src.m_left		= 0.0f;
	src.m_right		= 50.0f;
	src.m_bottom	= 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top		= 0.0f+m_y;
	dst.m_left		= 0.0f+m_x;
	dst.m_right		= 36.0f+m_x;
	dst.m_bottom	= 36.0f+m_y;

	//�O�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

	if (m_hp==3)
	{
		Font::StrDraw(L"HP:3/3", 0, 568, 32, c);
	}
	else if (m_hp == 2)
	{
		Font::StrDraw(L"HP:2/3", 0, 568, 32, c);
	}
	else if (m_hp == 1)
	{
		Font::StrDraw(L"HP:1/3", 0, 568, 32, c);
	}


	if (m_o == 10)
	{
		Font::StrDraw(L"10/10", 110, 568, 32, c);
	}
	else if (m_o == 9)
	{
		Font::StrDraw(L"9/10", 110, 568, 32, c);
	}
	else if (m_o ==8)
	{
		Font::StrDraw(L"8/10", 110, 568, 32, c);
	}
	else if (m_o == 7)
	{
		Font::StrDraw(L"7/10", 110, 568, 32, c);
	}
	else if (m_o ==6)
	{
		Font::StrDraw(L"6/10", 110, 568, 32, c);
	}
	else if (m_o == 5)
	{
		Font::StrDraw(L"5/10", 110, 568, 32, c);
	}
	else if (m_o == 4)
	{
		Font::StrDraw(L"4/10", 110, 568, 32, c);
	}
	else if (m_o == 3)
	{
		Font::StrDraw(L"3/10", 110, 568, 32, c);
	}
	else if (m_o == 2)
	{
		Font::StrDraw(L"2/10", 110, 568, 32, c);
	}
	else if (m_o == 1)
	{
		Font::StrDraw(L"1/10", 110, 568, 32, c);
	}
}
//600*800
