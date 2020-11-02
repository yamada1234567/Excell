//STLデバッグ機能をOFFにする
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameLで使用するヘッダー
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"


//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"

//コントラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//ゲームメイン初期化メソッド
void CSceneClear::InitScene()
{


	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

}


//ゲームメイン実行中メソッド
void CSceneClear::Scene()
{


}