#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjshield :public CObj
{
public:
	CObjshield(float x, float y);
	~CObjshield() {};
	void Init(); 
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;
};

