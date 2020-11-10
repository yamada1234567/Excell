#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:敵機
class CObjAlien :public CObj//Aーリアン
{
public:
	CObjAlien(float x, float y);
	~CObjAlien() {};
	void Init(); //イニシャ
	void Action();//アクション
	void Draw();//ドロー
	void SetVector(float vx, float vy);
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_left_bottom;
	float m_top_right;


	int m_hp;
	int m_time;
	int item;


};