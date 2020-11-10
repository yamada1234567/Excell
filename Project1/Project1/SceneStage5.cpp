//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include <stdlib.h>
#include <time.h>

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneStage5.h"
#include"GameHead.h"
//コンストラクタ
CSceneStage5::CSceneStage5()
{

}
//デストラクタ
CSceneStage5::~CSceneStage5()
{

}
//ゲームメイン初期化メソッド
void CSceneStage5::InitScene()
{
	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(Mrcury).png", 12, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//敵メテオ
	//CObjmeteoRD* obj_meteoRD = new CObjmeteoRD(100, 100);
	//Objs::InsertObj(obj_meteoRD, OBJ_meteoRD, 4);

	//背景
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);


	m_time = 0;
}
//ゲームメイン実行メソッド
void CSceneStage5::Scene()
{
	m_time++;
	
	
		if (m_time == 20)
		{
					/*CObjmeteoS* obj = new CObjmeteoS(100.0f, i*-100.0f);
					Objs::InsertObj(obj, OBJ_meteoS, 4);
					obj->SetVector(0.0f, 1.0f);*/
		}
	
}