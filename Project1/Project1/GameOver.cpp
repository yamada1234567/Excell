//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "GameOver.h"

//コントラクタ
GameOver::GameOver()
{

}

//デストラクタ
GameOver::~GameOver()
{

}

//ゲームメイン初期化メソッド
void GameOver::InitScene()
{
	//出力させる文字もグラフィックを作成
	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");


	//ゲームオーバーオブジェクトを作成
	GameOver* obj = new GameOver();
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);
}


//ゲームメイン実行中メソッド
void GameOver::Scene()
{


}