//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\Audio.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"

//コントラクタ
CSceneClear::CSceneClear(int Cou)
{
	Count = Cou;
}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームメイン初期化メソッド
void CSceneClear::InitScene()
{
	if(Count==7)
	{
	CObjClear* obj = new CObjClear(Count);
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

	//音楽読み込み
	Audio::LoadAudio(0, L"BGMSceneLast.wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//音楽スタート
	Audio::Start(0);

	}
	else
	{
		CObjClear* obj = new CObjClear(Count);
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		//音楽読み込み
		Audio::LoadAudio(0, L"BGMSceneClear.wav", BACK_MUSIC);

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster(1.0 - v);

		//音楽スタート
		Audio::Start(0);
	}
}


//ゲームメイン実行中メソッド
void CSceneClear::Scene()
{


}