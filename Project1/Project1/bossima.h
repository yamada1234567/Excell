#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;


class CObjBossima :public CObj
{
public:
	CObjBossima(float x, float y);
	~CObjBossima() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	int m_time;
};
