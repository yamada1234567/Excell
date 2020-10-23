//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameHead.h"
#include "hero.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjHero::Init()
{
	m_y = 500-16;
	m_x = (810/2)-16;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_f = true;

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_x, m_y, 37, 38, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//主人公機の弾丸発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//弾丸オブジェクト作成
			CObjBullet* obj_b = new CObjBullet(m_x+3.0f, m_y);
			Objs::InsertObj(obj_b, OBJ_BULLET, 1);

			m_f = false;
		}
	}
    else
    {
		m_f = true;
    }

	//操作
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 3.0f;
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 3.0f;

	}
	if (Input::GetVKey(VK_UP)==true)
	{
		m_y -= 3.0f;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += 3.0f;
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
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	if (hit->CheckObjNameHit(OBJ_meteoS) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//ELEMENT_ENEMYを持つオブジェクトと接触したら削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);     
		Hits::DeleteHitBox(this);   


	}


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

	//０番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
//600*800
