//#pragma once
////使用するヘッダー
//#include "GameL/SceneObjManager.h"
//
////使用するネームスペース
//using namespace GameL;
//
////オブジェクト：ゲームタイトル
//class GameOver :public Objs
{
public:
	GameOver();
	~GameOver();
	void InitScene();  //ゲームタイトルの初期化メソッド
	void Scene();      //ゲームタイトルの実行中メソッド
private:
};
