#pragma once

#include "GameL/SceneManager.h"


using namespace GameL;


class CSceneClear :public CScene
{
public:
	CSceneClear(int Cou);
	~CSceneClear();
	void InitScene();  
	void Scene();      
private:
	int Count;
};
