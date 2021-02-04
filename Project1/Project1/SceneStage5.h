#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStage5 :public CScene
{
public:
	CSceneStage5();
	~CSceneStage5();
	void InitScene();
	void Scene();
private:
	int m_time;
	float x;
	float y;
	int random;
	int pos;
	int pos2;
	int a;
};
