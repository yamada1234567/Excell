#pragma once

#include "GameL/SceneManager.h"


using namespace GameL;


class CSceneBossexp :public CScene
{
public:
	CSceneBossexp(int c);
	~CSceneBossexp();
	void InitScene();  
	void Scene();      
private:
	int Count;
	int m_time;
};

