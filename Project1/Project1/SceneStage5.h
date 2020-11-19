#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;
//シーン：ゲームメイン
class CSceneStage5 :public CScene
{
public:
	CSceneStage5();
	~CSceneStage5();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();    //ゲームメインの実行中メソッド
private:
	int m_time;
	float x;
	float y;
};
