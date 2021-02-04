#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjBomb :public CObj
{
public:
	CObjBomb(float x, float y);
	~CObjBomb() {};
	void Init(); 
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};