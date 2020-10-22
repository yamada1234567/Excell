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

//コントラクタ
GameOver::CSceneGameOver()
{

}

//デストラクタ
GameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化メソッド
void GameOver::InitScene()
{
	//出力させる文字もグラフィックを作成
	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//音楽読み込み
	Audio::LoadAudio(0, L"BGMGamover.wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);


	//ゲームオーバーオブジェクトを作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}


//ゲームメイン実行中メソッド
void CSceneGameOver::Scene()
{


}