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
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjHero::CObjHero(int c)
{

	C = c;
}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_y = 500-16;
	m_x = (810/2)-16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_f = true;
	m_g = true;
	m_bullet = 0;
	de_time = 0;
	bar_time = 0;

	m_hp = 5;
	m_o	=	15;

	Attack_Item=0;

	m_time = 0;
	Bullet_time = 100;

	Bar=0;

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




		//�ʏ�e�۔���
		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
				//���ˉ���炷
				Audio::Start(2);

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

		////�S�A�̒e�۔���
		//if (Input::GetVKey('X') == true)
		//{
		//	if (m_g == true)
		//	{
		//		//if (Attack_Item <= 1)
		//			for (int i = 0; i <= 40; i += 10)
		//			{
		//				//�R�e�ۃI�u�W�F�N�g�쐬
		//				CObjBullet* obj_b = new CObjBullet(m_x + 3.0f, m_y - i);
		//				Objs::InsertObj(obj_b, OBJ_BULLET, 1);
		//			}
		////			Attack_Item -= 1;
		/////*		}*/
		//		m_g = false;
		//	}
		//}
		//else
		//{

		//	m_g = true;
		//}

		////BOM�̒e�۔���
		//if (Input::GetVKey('B') == true)
		//{
		//	if (m_b == true)
		//	{
		//		//if (Attack_Item <= 1)
		//		
		//			////BOM�I�u�W�F�N�g�쐬
		//			CObjBomBullet* obj_b = new CObjBomBullet(m_x + 3.0f, m_y);
		//			Objs::InsertObj(obj_b, OBJ_BOM_BULLET, 1);
		//		//			Attack_Item -= 1;
		//		///*		}*/
		//		m_b = false;
		//	}
		//}
		//else
		//{
		//	m_b = true;
		//}



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

	if (Input::GetVKey('A') == false)
	{
		//�_���[�W����
		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			
			if (Bar <= 0)
			{
				m_hp -= 1;

				//�_���[�W����炷
				Audio::Start(4);

			}
			else
			{
				Bar -= 1;

			}

		}
	}
	if (Input::GetVKey('A') == false)
	{
		//�_�f�O�ŏ���
		if (m_time % 70 == 0)
		{
			m_o--;

			if (0 == m_o)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				//��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
				Scene::SetScene((CScene*)new CSceneGameOver(C));

			}
		}

	}

	//�V�[���h�A�C�e�������蔻��
	if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)
	{

		Bar = 3;

	}
	

	//if (Bar>0)
	//{
	//	
	//	bar_time++;
	//	if (bar_time==60)
	//	{
	//		Bar--;
	//		bar_time = 0;
	//	}
	//}


	//�_�f�A�C�e�������蔻��
	if (hit->CheckObjNameHit(OBJ_OXYGEN) != nullptr)
	{
		m_o = 15;

	}





	////�U�e�A�C�e������
	//if (hit->CheckObjNameHit(OBJ_ITEM) != nullptr)
	//{
	//	Attack_Item=4;
	//}


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

	//if (m_hp == 3)
	//{
	//	//�O�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	//	Draw::Draw(0, &src, &dst, c, 0.0f);
	//}
	//else if(m_hp == 2)
	//{

	//	Draw::Draw(15, &src, &dst, c, 0.0f);

	//}
	//else if (m_hp == 1)
	//{		

	//	Draw::Draw(16, &src, &dst, c, 0.0f);

	//}
	//else
	//{
	//	Draw::Draw(17, &src, &dst, c, 0.0f);


	//	de_time++;



	//	if (de_time == 100)
	//	{
	//		this->SetStatus(false);
	//		Hits::DeleteHitBox(this);
	//	}
	//	else
	//	{
	//			
	//			//��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
	//			Scene::SetScene((CScene*)new CSceneGameOver(C));

	//	}
	//	

	//}

	


	if (Bar>0)
	{
		Font::StrDraw(L"�o���A��(3)", 210, 568, 32, c);
		
		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 2)
	{
		Font::StrDraw(L"�o���A��(2)", 210, 568, 32, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 1)
	{
		Font::StrDraw(L"�o���A��(1)", 210, 568, 32, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}


	if (m_hp == 5)
	{
		Font::StrDraw(L"HP:5/5", 0, 568, 32, c);

		//�O�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(0, &src, &dst, c, 0.0f);


	}	
	else if (m_hp == 4)
	{
		Font::StrDraw(L"HP:4/5", 0, 568, 32, c);

		//�O�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(15, &src, &dst, c, 0.0f);


	}
	else if (m_hp==3)
	{
		Font::StrDraw(L"HP:3/5", 0, 568, 32, c);

		//�O�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
		Draw::Draw(15, &src, &dst, c, 0.0f);


	}
	else if (m_hp == 2)
	{
		Font::StrDraw(L"HP:2/5", 0, 568, 32, c);

		Draw::Draw(16, &src, &dst, c, 0.0f);

	}
	else if (m_hp == 1)
	{
		Font::StrDraw(L"HP:1/5", 0, 568, 32, c);

		Draw::Draw(16, &src, &dst, c, 0.0f);

	}
	else
	{
		Font::StrDraw(L"HP:0/5", 0, 568, 32, c);
	    Draw::Draw(17, &src, &dst, c, 0.0f);

		de_time++;

		m_vx = 0;
		m_vy = 0;



			if (de_time == 11)
			{


				this->SetStatus(false);
				Hits::DeleteHitBox(this);
			
					//��l�����łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
					Scene::SetScene((CScene*)new CSceneGameOver(C));


			}



	}

	

	if (m_o == 15)
	{
		Font::StrDraw(L"15/15", 110, 568, 32, c);
	}
	else if (m_o == 14)
	{
		Font::StrDraw(L"14/15", 110, 568, 32, c);
	}
	else if (m_o ==13)
	{
		Font::StrDraw(L"13/15", 110, 568, 32, c);
	}
	else if (m_o == 12)
	{
		Font::StrDraw(L"12/15", 110, 568, 32, c);
	}
	else if (m_o == 11)
	{
		Font::StrDraw(L"11/15", 110, 568, 32, c);
	}
	else if (m_o == 10)
	{
		Font::StrDraw(L"10/15", 110, 568, 32, c);
	}
	else if (m_o == 9)
	{
		Font::StrDraw(L"9/15", 110, 568, 32, c);
	}
	else if (m_o ==8)
	{
		Font::StrDraw(L"8/15", 110, 568, 32, c);
	}
	else if (m_o == 7)
	{
		Font::StrDraw(L"7/15", 110, 568, 32, c);
	}
	else if (m_o ==6)
	{
		Font::StrDraw(L"6/15", 110, 568, 32, c);
	}
	else if (m_o == 5)
	{
		Font::StrDraw(L"5/15", 110, 568, 32, c);
	}
	else if (m_o == 4)
	{
		Font::StrDraw(L"4/15", 110, 568, 32, c);
	}
	else if (m_o == 3)
	{
		Font::StrDraw(L"3/10", 110, 568, 32, c);
	}
	else if (m_o == 2)
	{
		Font::StrDraw(L"2/15", 110, 568, 32, c);
	}
	else if (m_o == 1)
	{
		Font::StrDraw(L"1/15", 110, 568, 32, c);
	}
}
//600*800
