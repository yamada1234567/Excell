//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "triplebullet.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjTripleBullet::CObjTripleBullet(float x, float y, float r, float speed)
{
	m_x = x;
	m_y = y;
	m_r = r;
	m_speed = speed;
}

//イニシャライズ
void CObjTripleBullet::Init()
{
	m_vx = cos(3.14f/180.0f*m_r);
	m_vy = sin(3.14f / 180.0f * m_r);


	//ベクトルの長さを求める
	float r = 0.0f;
	r = m_vx * m_vx + m_vy * m_vy;
	r = sqrt(r);//rをルートを求める

	//長さが０かどうか調べる
	if (r == 0.0f)
	{
		;//０ならそのまま
	}
	else
	{
		//正規化
		m_vx = 1.0f / r * m_vx;
		m_vy = 1.0f / r * m_vy;
	}

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_TRIPLEBULLET, 1);
}

//アクション
void CObjTripleBullet::Action()
{
	//移動
	m_y += m_vx * m_speed;
	m_x -= m_vx * m_speed;

	

	//hitbox更新用ポインターの取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//領域外に出たら削除
	if (m_x < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//弾丸当たってるか調べる
	if (hit->CheckObjNameHit(OBJ_meteoS) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_meteoM) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_meteoL) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_BOSS) != nullptr)
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
void CObjTripleBullet::Draw()
{
	//描写カラー情報 R=RED G=Green B=Blue A=alpha
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//1番に登録したグラフィックをの情報をもとに描画
	Draw::Draw(1, &src, &dst, c, m_r);
}