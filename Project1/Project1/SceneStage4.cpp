//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneStage4.h"
#include"GameHead.h"
//コンストラクタ
CSceneStage4::CSceneStage4()
{

}
//デストラクタ
CSceneStage4::~CSceneStage4()
{
	x = 0.0f;
	y = 0.0f;
}
//ゲームメイン初期化メソッド
void CSceneStage4::InitScene()
{
	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(Venus).png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(4);//主人公オブジェクト作成
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
void CSceneStage4::Scene()
{
	m_time++;

	
	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 200);
	}
	//出力する時間(timeが50になると出力)
	if (m_time % 50 == 0)
	{
		//右下に進む隕石出力
		CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoRD, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//出力する時間(timeが50になると出力)
	if (m_time % 50 == 0)
	{
		//左下に進む隕石出力
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//出力する時間(timeが60になると出力)
	if (m_time % 60 == 0)
	{
		//S字に進む隕石出力
		CObjmeteoSin* obj = new CObjmeteoSin(368.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoSIN, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	
	//出力する時間(timeが50になると出力)
	if (m_time % 70 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(290.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}

	//出力する時間(timeが40になると出力)
	if (m_time % 66 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(460.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 83 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(400.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 67 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(110.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 55 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(330.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 50 == 0)
	{
		//小隕石出力
		CObjmeteoS* obj = new CObjmeteoS(670.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//出力する時間(timeが60になると出力)
	if (m_time % 70 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(70.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 100 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(610.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 90 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(390.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//出力する時間(timeが70になると出力)
	if (m_time % 88 == 0)
	{
		//大隕石出力
		CObjmeteoL* obj = new CObjmeteoL(300.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 80 == 0)
	{
		//大隕石出力
		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 60 == 0)
	{
		//大隕石出力
		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	
	//出力する時間(timeが500になると出力)
	if (m_time == 1500)
	{
		//ボス出力
		CObjBoss4* obj = new CObjBoss4(100.0f, 10.0f);
		Objs::InsertObj(obj, OBJ_BOSS4, 13);
	}
}