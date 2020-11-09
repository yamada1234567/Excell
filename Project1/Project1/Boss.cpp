//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Boss.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBoss::CObjBoss(float x, float y)
{

	//表示位置
	m_x = x+100;
	m_y = y-150; 

}

//イニシャライズ
void CObjBoss::Init()
{
	m_hp = 20;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HiyBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 420, 420, ELEMENT_ENEMY, OBJ_BOSS, 6);
}
//アクション
void CObjBoss::Action()
{
	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	////ボス機が完全に領域外に出たらボス機を破棄する
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	//if (check == false)
	//{
	//	this->SetStatus(false);//自身に削除命令を出す
	//	Hits::DeleteHitBox(this);//ボス機が所有するHitBoxに削除する
	//}

	//ダメージ判定
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//クリアに移動
			Scene::SetScene(new CSceneClear(0));
			
		}

	}
}
//ドロー
void CObjBoss::Draw()
{
	//描画カラー情報 R=RED G=Green B=Blue A=alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切れ取り設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 530.0f;
	src.m_bottom = 530.0f;
	//表示位置
	dst.m_top = 0.0f+m_y;
	dst.m_left = 420.0f+m_x;
	dst.m_right = 0.0f+m_x;
	dst.m_bottom = 420.0f+ m_y;

	//1番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(6, &src, &dst, c, 0.0f);
}