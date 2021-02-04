#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjAlien :public CObj
{
public:
	CObjAlien(float x, float y);
	~CObjAlien() {};
	void Init(); 
	void Action();
	void Draw();
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

	int de_time;
};