#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjmeteoL :public CObj
{
public:
	CObjmeteoL(float x, float y);
	~CObjmeteoL() {};
	void Init(); 
	void Action();
	void Draw();
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

	int de_time;
	
};

