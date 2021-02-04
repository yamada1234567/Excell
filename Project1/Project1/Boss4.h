#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjBoss4 :public CObj
{
public:
	CObjBoss4(float x, float y);
	~CObjBoss4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;

	int de_time;
};