#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームタイトル
class CSceneDes :public CScene
{
public:
	CSceneDes();  //コンストラクタ
	~CSceneDes();
	void InitScene();  //ゲームタイトルの初期化メソッド
	void Scene();      //ゲームタイトルの実行中メソッド
private:
};
