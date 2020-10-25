//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"
//コンストラクタ
CSceneMain::CSceneMain()
{

}
//デストラクタ
CSceneMain::~CSceneMain()
{

}
//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	//Draw::LoadImage(L"meteoS.png", 4, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj,OBJ_HERO,1);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//敵メテオ
	CObjmeteoS* obj_meteoS = new CObjmeteoS(100,100);
	Objs::InsertObj(obj_meteoS, OBJ_meteoS, 4);

	//敵メテオ
	CObjmeteoM* obj_meteoM = new CObjmeteoM(100, 100);
	Objs::InsertObj(obj_meteoM, OBJ_meteoM, 3);
	
	//敵メテオ
	CObjmeteoL* obj_meteoL = new CObjmeteoL(100, 100);
	Objs::InsertObj(obj_meteoL, OBJ_meteoL, 2);

	//アイテム
	//CObjitem* obj_item = new CObjitem(100, 100);
	//Objs::InsertObj(obj_item, OBJ_ITEM, 5);
	
	//ボス
	/*CObjBoss* obj_Boss = new CObjBoss(300, 120);
	Objs::InsertObj(obj_meteoS, OBJ_BOSS, 4);*/


}
//ゲームメイン実行メソッド
void CSceneMain::Scene()
{
	
}