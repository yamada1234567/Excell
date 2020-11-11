#pragma once
//使用するヘッダー
#include "GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームタイトル
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver(int c);
	~CSceneGameOver();
	void InitScene();  //ゲームタイトルの初期化メソッド
	void Scene();      //ゲームタイトルの実行中メソッド
private:
	int C;
};
