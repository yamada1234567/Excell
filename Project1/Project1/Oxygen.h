#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjOxygen :public CObj
{
public:
	CObjOxygen(float x, float y);
	~CObjOxygen() {};
	void Init(); 
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};

