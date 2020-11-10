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


	int random;
		if (m_time == 20)
		{
				srand(time(NULL));
				random = rand() % 5;
				if (random == 0)
				{
					CObjmeteoS* obj = new CObjmeteoS(300.0f, -100.0f);
					Objs::InsertObj(obj, OBJ_meteoS, 4);
					obj->SetVector(0.0f, 1.0f);
				}
				if (random == 1)
				{
					CObjmeteoM* obj = new CObjmeteoM(300.0f, -100.0f);
					Objs::InsertObj(obj, OBJ_meteoM, 3);
					obj->SetVector(0.0f, 1.0f);
				}
				if (random == 2)
				{
					CObjmeteoL* obj = new CObjmeteoL(300.0f, -100.0f);
					Objs::InsertObj(obj, OBJ_meteoL, 2);
					obj->SetVector(0.0f, 1.0f);
				}
				if (random == 3)
				{
					CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 60.0f);
					Objs::InsertObj(obj, OBJ_meteoRD, 4);
					obj->SetVector(1.0f, 1.0f);
				}
				if (random == 4)
				{
					CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
					Objs::InsertObj(obj, OBJ_meteoLD, 4);
					obj->SetVector(1.0f, 1.0f);
				}
		}
		random = 0;
		if (m_time == 20)
		{
		
			random = rand() % 5;
			if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(300.0f, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 1)
			{
				CObjmeteoM* obj = new CObjmeteoM(300.0f, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 2)
			{
				CObjmeteoL* obj = new CObjmeteoL(300.0f,  -100.0f);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 60.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			if (random == 4)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
		}
}