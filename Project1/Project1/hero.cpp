
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "hero.h"

#include "UtilityModule.h"


#include "GameL/DrawFont.h"
#include "GameL\Audio.h"


using namespace GameL;

CObjHero::CObjHero(int c)
{

	C = c;
}


void CObjHero::Init()
{
	m_y = 500-16;
	m_x = (810/2)-16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_f = true;
	m_bullet = 0;
	time = 0;
	de_time = 0;
	bar_time = 0;

	m_hp = 5;
	m_o	= 15;

	Attack_Item=0;

	m_time = 0;
	Bullet_time = 100;

	Bar = 0;

	
	Hits::SetHitBox(this, m_x, m_y, 37, 38, ELEMENT_PLAYER, OBJ_HERO, 1);
}


void CObjHero::Action()
{

	m_time++;



	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);




		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
	
				Audio::Start(2);

				CObjBullet* obj_b = new CObjBullet(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_BULLET, 1);

			

				m_f = false;

			}


		}
		
		else if (Input::GetVKey('X') == true)
		{
			if (m_f == true)
			{
				if (Attack_Item != 0)
				{

					
					CObjBomBullet* obj_b = new CObjBomBullet(m_x + 3.0f, m_y);
					Objs::InsertObj(obj_b, OBJ_BOM_BULLET, 1);


					Attack_Item -= 1;
				}
				m_f = false;
			}
		}
		else
		{
			m_f = true;
		}




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



	m_vx = 0.0f;
	m_vy = 0.0f;



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


	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);


	if (r==0.0f)
	{

	}
	else
	{

		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}




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




		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			
			if (Bar <= 0)
			{
				m_hp -= 1;


				Audio::Start(4);

			}
			else
			{
				Bar -= 1;

			}

		}


		if (m_time % 70 == 0)
		{
			m_o--;

			if (0 == m_o)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);


				
				Scene::SetScene((CScene*)new CSceneGameOver(C));
				
				return;

			}
		}


	if (hit->CheckObjNameHit(OBJ_SHIELD) != nullptr)
	{

		Bar = 3;

	}
	





	if (hit->CheckObjNameHit(OBJ_OXYGEN) != nullptr)
	{
		m_o = 15;

	}






	if (hit->CheckObjNameHit(OBJ_BOMB) != nullptr)
	{
		Attack_Item+=2;
	}


}



void CObjHero::Draw()
{

	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;


	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom	= 50.0f;


	dst.m_top		= 0.0f+m_y;
	dst.m_left		= 0.0f+m_x;
	dst.m_right		= 36.0f+m_x;
	dst.m_bottom	= 36.0f+m_y;




	if (Attack_Item>=1)
	{

		Font::StrDraw(L"(Bomégópâ¬î\)", 500, 568, 28, c);

	}
	if (Bar==3)
	{
		Font::StrDraw(L"ÉoÉäÉAíÜ(3)", 320, 568, 28, c);
		
		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 2)
	{
		Font::StrDraw(L"ÉoÉäÉAíÜ(2)", 320, 568, 28, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 1)
	{
		Font::StrDraw(L"ÉoÉäÉAíÜ(1)", 320, 568, 28, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}


	if (m_hp == 5)
	{
		Font::StrDraw(L"HP:5/5", 0, 568, 32, c);

		
		Draw::Draw(0, &src, &dst, c, 0.0f);


	}	
	else if (m_hp == 4)
	{
		Font::StrDraw(L"HP:4/5", 0, 568, 32, c);

	
		Draw::Draw(15, &src, &dst, c, 0.0f);


	}
	else if (m_hp==3)
	{
		Font::StrDraw(L"HP:3/5", 0, 568, 32, c);

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
			
				
				Scene::SetScene((CScene*)new CSceneGameOver(C));
					
				return;	

			}



	}

	

	if (m_o == 15)
	{
		Font::StrDraw(L"é_ëfÅF15/15", 110, 568, 32, c);
	}
	else if (m_o == 14)
	{
		Font::StrDraw(L"é_ëfÅF14/15", 110, 568, 32, c);
	}
	else if (m_o ==13)
	{
		Font::StrDraw(L"é_ëfÅF13/15", 110, 568, 32, c);
	}
	else if (m_o == 12)
	{
		Font::StrDraw(L"é_ëfÅF12/15", 110, 568, 32, c);
	}
	else if (m_o == 11)
	{
		Font::StrDraw(L"é_ëfÅF11/15", 110, 568, 32, c);
	}
	else if (m_o == 10)
	{
		Font::StrDraw(L"é_ëfÅF10/15", 110, 568, 32, c);
	}
	else if (m_o == 9)
	{
		Font::StrDraw(L"é_ëfÅF9/15", 110, 568, 32, c);
	}
	else if (m_o ==8)
	{
		Font::StrDraw(L"é_ëfÅF8/15", 110, 568, 32, c);
	}
	else if (m_o == 7)
	{
		Font::StrDraw(L"é_ëfÅF7/15", 110, 568, 32, c);
	}
	else if (m_o ==6)
	{
		Font::StrDraw(L"é_ëfÅF6/15", 110, 568, 32, c);
	}
	else if (m_o == 5)
	{
		Font::StrDraw(L"é_ëfÅF5/15", 110, 568, 32, c);
	}
	else if (m_o == 4)
	{
		Font::StrDraw(L"é_ëfÅF4/15", 110, 568, 32, c);
	}
	else if (m_o == 3)
	{
		Font::StrDraw(L"é_ëfÅF3/10", 110, 568, 32, c);
	}
	else if (m_o == 2)
	{
		Font::StrDraw(L"é_ëfÅF2/15", 110, 568, 32, c);
	}
	else if (m_o == 1)
	{
		Font::StrDraw(L"é_ëfÅF1/15", 110, 568, 32, c);
	}
}

