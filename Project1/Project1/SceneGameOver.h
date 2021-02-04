#pragma once

#include "GameL/SceneManager.h"


using namespace GameL;


class CSceneGameOver :public CScene
{
public:
	CSceneGameOver(int c);
	~CSceneGameOver();
	void InitScene();
	void Scene();  
private:
	int C;
};
