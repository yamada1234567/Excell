//使用するヘッダーファイル
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

//使用するネームスペース
using namespace GameL;

CObjHero::CObjHero(int c)
{

	C = c;
}

//イニシャライズ
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

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 37, 38, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	m_time++;

	//Hitboxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);




		//通常弾丸発射
		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
				//発射音を鳴らす
				Audio::Start(2);

				//弾丸オブジェクト作成
				CObjBullet* obj_b = new CObjBullet(m_x + 3.0f, m_y);
				Objs::InsertObj(obj_b, OBJ_BULLET, 1);

			

				m_f = false;

			}


		}
		else
		{
			
			m_f = true;
		}

		////４連の弾丸発射
		//if (Input::GetVKey('X') == true)
		//{
		//	if (m_g == true)
		//	{
		//		//if (Attack_Item <= 1)
		//			for (int i = 0; i <= 40; i += 10)
		//			{
		//				//３弾丸オブジェクト作成
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

		////BOMの弾丸発射
		//if (Input::GetVKey('B') == true)
		//{
		//	if (m_b == true)
		//	{
		//		//if (Attack_Item <= 1)
		//		
		//			////BOMオブジェクト作成
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



	//操作
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

	//移動ベクトル初期化
	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの方向にベクトルの速度を入れる
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

	//ベクトルの長さを求める
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//rをルートを求める

	//長さが０かどうか調べる
	if (r==0.0f)
	{
		;//０ならそのまま
	}
	else
	{
		//正規化
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}



	//範囲外に行かない処理
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

	//Hitboxの内容を更新
	//CHitBox* hit = Hits::GetHitBox(this);
	//hit->SetPos(m_x, m_y);

	if (Input::GetVKey('A') == false)
	{
		//ダメージ判定
		if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
		{
			
			if (Bar <= 0)
			{
				m_hp -= 1;

				//ダメージ音を鳴らす
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
		//酸素０で消滅
		if (m_time % 70 == 0)
		{
			m_o--;

			if (0 == m_o)
			{
				this->SetStatus(false);
				Hits::DeleteHitBox(this);

				//主人公消滅でシーンをゲームオーバーに移行する
				Scene::SetScene((CScene*)new CSceneGameOver(C));

			}
		}

	}

	//シールドアイテム当たり判定
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


	//酸素アイテム当たり判定
	if (hit->CheckObjNameHit(OBJ_OXYGEN) != nullptr)
	{
		m_o = 15;

	}





	////散弾アイテム判定
	//if (hit->CheckObjNameHit(OBJ_ITEM) != nullptr)
	//{
	//	Attack_Item=4;
	//}


}


//ドロー
void CObjHero::Draw()
{

	//描画カラー情報　R＝Red G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top		= 0.0f;
	src.m_left		= 0.0f;
	src.m_right		= 50.0f;
	src.m_bottom	= 50.0f;

	//表示位置の設定
	dst.m_top		= 0.0f+m_y;
	dst.m_left		= 0.0f+m_x;
	dst.m_right		= 36.0f+m_x;
	dst.m_bottom	= 36.0f+m_y;

	//if (m_hp == 3)
	//{
	//	//０番目に登録したグラフィックをsrc・dst・cの情報を元に描画
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
	//			//主人公消滅でシーンをゲームオーバーに移行する
	//			Scene::SetScene((CScene*)new CSceneGameOver(C));

	//	}
	//	

	//}

	


	if (Bar>0)
	{
		Font::StrDraw(L"バリア中(3)", 210, 568, 32, c);
		
		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 2)
	{
		Font::StrDraw(L"バリア中(2)", 210, 568, 32, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}
	else if (Bar == 1)
	{
		Font::StrDraw(L"バリア中(1)", 210, 568, 32, c);

		Draw::Draw(22, &src, &dst, c, 0.0f);
	}


	if (m_hp == 5)
	{
		Font::StrDraw(L"HP:5/5", 0, 568, 32, c);

		//０番目に登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(0, &src, &dst, c, 0.0f);


	}	
	else if (m_hp == 4)
	{
		Font::StrDraw(L"HP:4/5", 0, 568, 32, c);

		//０番目に登録したグラフィックをsrc・dst・cの情報を元に描画
		Draw::Draw(15, &src, &dst, c, 0.0f);


	}
	else if (m_hp==3)
	{
		Font::StrDraw(L"HP:3/5", 0, 568, 32, c);

		//０番目に登録したグラフィックをsrc・dst・cの情報を元に描画
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
			
					//主人公消滅でシーンをゲームオーバーに移行する
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
