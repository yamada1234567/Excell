//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "BomBullet.h"
#include "GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBomBullet::CObjBomBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBomBullet::Init()
{
	m_vx = 0.0f;

	//当たり判定作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_BOM_BULLET, 1);
}

//アクション
void CObjBomBullet::Action()
{
	m_y += -12.0f;

	m_x += m_vx;

	//領域外に出たら削除
	if (m_x < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//hitbox更新用ポインターの取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);



	//ELEMENT_ENEMYを持つオブジェクトと接触したら削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjBom* obj_b = new CObjBom(m_x, m_y);
		Objs::InsertObj(obj_b, OBJ_BOM, 1);
	}
}

//ドロー
void CObjBomBullet::Draw()
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
	Draw::Draw(1, &src, &dst, c, 0.0f);
}