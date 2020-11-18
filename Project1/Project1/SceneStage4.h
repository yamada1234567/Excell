#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;
//シーン：ゲームメイン
class CSceneStage4 :public CScene
{
public:
	CSceneStage4();
	~CSceneStage4();
	void InitScene();//ゲームメインの初期化メソッド
	void Scene();    //ゲームメインの実行中メソッド
private:
	int m_time;
	float x;
	float y;
};
