#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStage4 :public CScene
{
public:
	CSceneStage4();
	~CSceneStage4();
	void InitScene();
	void Scene(); 
private:
	int m_time;
	float x;
	float y;
};
