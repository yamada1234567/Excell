#pragma once

#include "GameL\SceneObjManager.h"

using namespace GameL;


class CObjBom : public CObj
{
public:
	CObjBom(float x, float y);
	~CObjBom() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float si_x;
	float si_y;
	float m_vx;
	int m_time;
};
