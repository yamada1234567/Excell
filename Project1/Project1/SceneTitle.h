#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームタイトル
class CSceneTitle :public CScene
{
public:
	CSceneTitle();  //コンストラクタ
	~CSceneTitle();
	void InitScene();  //ゲームタイトルの初期化メソッド
	void Scene();      //ゲームタイトルの実行中メソッド
private:
};