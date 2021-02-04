#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;


class CObjBullet : public CObj
{
public :
	CObjBullet(float x, float y); 
	~CObjBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
};
