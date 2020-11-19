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
#include"SceneStage2.h"
#include"GameHead.h"
//コンストラクタ
CSceneStage2::CSceneStage2()
{

}
//デストラクタ
CSceneStage2::~CSceneStage2()
{
	x = 0.0f;
	y = 0.0f;
}
//ゲームメイン初期化メソッド
void CSceneStage2::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"BGMSceneMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SEbullet.wav", EFFECT);
	Audio::LoadAudio(3, L"SEEnemyexp.wav", EFFECT);
	Audio::LoadAudio(4, L"SEheroexp.wav", EFFECT);

	//ボリュームを1.5増やす
	float v = Audio::VolumeMaster(1.5);

	//音楽スタート
	Audio::Start(0);

	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(Mars).png", 9, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(2);//主人公オブジェクト作成
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
void CSceneStage2::Scene()
{
	m_time++;
	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 20);
	}

	//小
	if (m_time % 40 == 0)
	{
		x = 300.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//小
	if (m_time % 55 == 0)
	{
		x = 100.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 45 == 0)
	{
		x = 220.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 65 == 0)
	{
		x = 450.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 70 == 0)
	{
		x = 600.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 55 == 0)
	{
		x = 200.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time % 50 == 0)
	{
		x = 700.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time % 70 == 0)
	{
		x = 500.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	//メテオ中
	if (m_time % 150 == 0)
	{
		x = 700.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time % 70 == 0)
	{
		x = 0.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time % 70 == 0)
	{
		x = 750.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time % 200 == 0)
	{
		x = 400.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time % 170 == 0)
	{
		x = 250.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time % 140 == 0)
	{
		x = 400.0f;

		CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	//ボス
	if (m_time == 1300)
	{
		x = 100;
		CObjBoss2* obj = new CObjBoss2(x, 10.0f);
		Objs::InsertObj(obj, OBJ_BOSS2, 9);
	}
}