#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:敵機
class CObjmeteoM :public CObj//メテオ中 
{
public:
	CObjmeteoM(float x, float y);
	~CObjmeteoM() {};
	void Init(); //イニシャ
	void Action();//アクション
	void Draw();//ドロー
	void SetVector(float vx, float vy);
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;
	
};
