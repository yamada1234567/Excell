#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:敵機
class CObjitem :public CObj//アイテム
{
public:
	CObjitem(float x, float y);
	~CObjitem() {};
	void Init(); //イニシャ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;
};
