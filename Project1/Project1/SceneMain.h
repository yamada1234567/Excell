#pragma once

#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();
	void Scene();
private:
	int m_time;
	float x;
	float y;
;
};