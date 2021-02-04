#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;


class CObjBomBullet : public CObj
{
public:
	CObjBomBullet(float x, float y); 
	~CObjBomBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
};
