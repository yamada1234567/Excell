#pragma once

#include "GameL/SceneObjManager.h"

using namespace GameL;


class CObjHeroime :public CObj
{
public:
	CObjHeroime();
	~CObjHeroime() {};

	void Init();
	void Action();
	void Draw();

private:
	float m_y;
	float m_x;
};


