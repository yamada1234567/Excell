//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL/DrawTexture.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コントラクタ
CSceneDes::CSceneDes()
{

}

//デストラクタ
CSceneDes::~CSceneDes()
{

}

//ゲームメイン初期化メソッド
void CSceneDes::InitScene()
{
	Draw::LoadImage(L"操作方法.png", 1, TEX_SIZE_512);


	//音楽読み込み
	//Audio::LoadAudio(0, L"BGMSceneTitle.wav", SOUND_TYPE::BACK_MUSIC);

	////バックミュージックスタート
	//float Volume = Audio::VolumeMaster(-0.3f); //マスターボリュームを0.8下げる
	//Audio::Start(0);  //音楽スタート


	//タイトルオブジェクトを作成
	CObjDes* obj = new CObjDes();   //タイトルオブジェクト作成
	Objs::InsertObj(obj, OBJ_DES, 10);//主人公オブジェクト登録
}
//ゲームメイン実行中メソッド
void CSceneDes::Scene()
{


}