#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStage2 :public CScene
{
public:
	CSceneStage2();
	~CSceneStage2();
	void InitScene();
	void Scene(); 
private:
	int m_time;
	float x;
	float y;
};
