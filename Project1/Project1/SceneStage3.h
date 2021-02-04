#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStage3 :public CScene
{
public:
	CSceneStage3();
	~CSceneStage3();
	void InitScene();
	void Scene();   
private:
	int m_time;
	float x;
	float y;

};