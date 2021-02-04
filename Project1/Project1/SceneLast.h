#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneLast :public CScene
{
public:
	CSceneLast();
	~CSceneLast();
	void InitScene();
	void Scene();    
private:
	int m_time;
	float x;
	float y;

};
