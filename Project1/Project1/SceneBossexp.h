#pragma once
//使用するヘッダー
#include "GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームタイトル
class CSceneBossexp :public CScene
{
public:
	CSceneBossexp(int c);
	~CSceneBossexp();
	void InitScene();  //ゲームタイトルの初期化メソッド
	void Scene();      //ゲームタイトルの実行中メソッド
private:
	int Count;
	int m_time;
};

