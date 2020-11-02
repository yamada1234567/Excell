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
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{

	//音楽読み込み
	//Audio::LoadAudio( 0 , L"BGMTitle.wav", SOUND_TYPE::BACK_MUSIC);

	//バックミュージックスタート
	//float Volume = Audio::VolumeMaster(-0.8f); //マスターボリュームを0.8下げる
	//Audio::Start(0);  //音楽スタート


	//タイトルオブジェクトを作成
	CObjTitle* obj = new CObjTitle();   //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト登録
}


//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{


}