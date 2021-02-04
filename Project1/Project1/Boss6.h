#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;


class CObjBoss6 :public CObj
{
public:
	CObjBoss6(float x, float y);
	~CObjBoss6() {};
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