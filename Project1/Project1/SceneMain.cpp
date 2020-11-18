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
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(moon).png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(1);//主人公オブジェクト作成
	Objs::InsertObj(obj,OBJ_HERO,1);//作った主人公オブジェクトをオブジェクトマネージャーに登録




	//背景
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	m_time = 0;
}
//ゲームメイン実行メソッド
void CSceneMain::Scene()
{
	
	//クリアに移動
	//Scene::SetScene(new CSceneClear());
	
	//時間
	m_time++;

	if (m_time == 10)
	{
		CObjmeteoS* obj = new CObjmeteoS(400.0f, 50.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}


	//出現する時間
	if (m_time==10)
	{
		CObjAlien* obj= new CObjAlien(0,50);
		Objs::InsertObj(obj, OBJ_Alien, 20);

	}


}