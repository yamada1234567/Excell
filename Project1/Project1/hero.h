#pragma once
//使用ヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero:public CObj
{
public:
	CObjHero(int c);
	~CObjHero(){};

	void Init();
	void Action();
	void Draw();

private:
	float m_y; //主人公機 y方向移動用変数
	float m_x; //主人公機 x方向移動用変数
	
	bool  m_f_bu; //弾丸発射制御用
	bool  m_f_bom; //弾丸発射制御用

	float m_vx;//ｘ方向ベクトル変換用
	float m_vy;//ｙ方向ベクトル変換用

	int m_hp;
	int m_bullet;

	int m_o;
	int m_time;
	int de_time;
	int bar_time;
	int time;

	int Bullet_time;
	int Attack_Item;
	int Bar;
	int C;
};

