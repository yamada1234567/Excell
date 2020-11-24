//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include "SceneBossexp.h"
#include"GameHead.h"
#include <stdlib.h>
#include <time.h>

//コントラクタ
CSceneBossexp::CSceneBossexp()
{

}

//デストラクタ
CSceneBossexp::~CSceneBossexp()
{

}

//ゲームメイン初期化メソッド
void CSceneBossexp::InitScene()
{
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);


	//主人公オブジェクト作成
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);




}


//ゲームメイン実行中メソッド
void CSceneBossexp::Scene()
{


}