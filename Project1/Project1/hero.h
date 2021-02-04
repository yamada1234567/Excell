#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjHero:public CObj
{
public:
	CObjHero(int c);
	~CObjHero(){};

	void Init();
	void Action();
	void Draw();

private:
	float m_y; 
	float m_x;
	
	bool  m_f_bu; 
	bool  m_f_bom; 

	float m_vx;
	float m_vy;

	int m_hp;
	int m_bullet;

	int m_o;
	int m_time;
	int de_time;
	int bar_time;
	int time;

	int Bullet_time;
	int Attack_Item;
	int Bar;
	int C;
};

