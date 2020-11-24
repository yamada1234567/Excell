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
#include"SceneLast.h"
#include"GameHead.h"
#include <time.h>
//コンストラクタ
CSceneLast::CSceneLast()
{

}
//デストラクタ
CSceneLast::~CSceneLast()
{
	x = 0.0f;
	y = 0.0f;


}
//ゲームメイン初期化メソッド
void CSceneLast::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"BGMSceneMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMLastBoss.wav", BACK_MUSIC);

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
	Draw::LoadImage(L"Boss(Sun).png", 13, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);
	Draw::LoadImage(L"隕石爆発.png", 50, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(6);//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 1);//作った主人公オブジェクトをオブジェクトマネージャーに登録


	//背景
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);


	m_time = 0;
}
//ゲームメイン実行メソッド
void CSceneLast::Scene()
{
	m_time++;
	int random;
	int pos;
	int pos2;
	int x;
	int a;

	for (int i = 0; i < 10000; i++)
	{
		pos = 0;
		srand((int)time(NULL));
		pos = rand() % 3;
		if (pos == 0)
		{
			x = 200.0f;
		}
		else if (pos == 1)
		{
			x = 400.0f;
		}
		else if (pos == 2)
		{
			x = 600.0f;
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		pos2 = 0;
		srand((int)time(NULL));
		pos2 = rand() % 3;
		if (pos2 == 0)
		{
			a = 50.0f;
		}
		else if (pos == 1)
		{
			a = 60.0f;
		}
		else if (pos == 2)
		{
			a = 70.0f;
		}
	}

	for (int i = 0; i < 10000; i++)//ランダム隕石
	{
		if (m_time == i * 60)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoM* obj = new CObjmeteoM(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 2)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoM* obj = new CObjmeteoM(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 5)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 6)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 7)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}

	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 200);
	}
	if (m_time % 100 == 0)
	{
		x = 200.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 100 == 0)
	{
		x = 200.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 110 == 0)
	{
		x = 350.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 160 == 0)
	{
		x = 600.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 150 == 0)
	{
		x = 550.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//右下
	if (m_time % 10 == 0)
	{ 	
		if (m_time % 100 == 0)
		{
			y=20.0;
						
			CObjmeteoRD* obj = new CObjmeteoRD(0.0f, y);
			Objs::InsertObj(obj, OBJ_meteoRD, 4);
			obj->SetVector(1.0f, 1.0f);
		}
	}
	if (m_time % 110 == 0)
	{
		y = 200.0;

		CObjmeteoRD* obj = new CObjmeteoRD(0.0f, y);
		Objs::InsertObj(obj, OBJ_meteoRD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
		
	//左下
	if (m_time % 130 == 0)
	{
		y = 20.0;
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, y);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
	if (m_time % 80 == 0)
	{
		y = 200.0;
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, y);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//小
	if (m_time % 40 == 0)
	{
		x= 300.0f;

			CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoS, 4);
			obj->SetVector(0.0f, 1.0f);
	

	}
	if (m_time % 60 == 0)
	{
		x = 500.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time % 200 == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			x = i * 100.0f;

			CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoS, 4);
			obj->SetVector(0.0f, 1.0f);
		}
	}

	//中
	if (m_time % 80 == 0)
	{
	
	
		if (x==300)
		{

			CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoM, 4);
			obj->SetVector(0.0f, 1.0f);

			x = 800.0f;
		}
		else
		{

			CObjmeteoM* obj = new CObjmeteoM(x, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoM, 4);
			obj->SetVector(0.0f, 1.0f);

			x = 300.0f;
		}

	}

	//大
	if (m_time == 300)
	{
		x = 650.0f;

		CObjmeteoL* obj = new CObjmeteoL(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time%470 == 0)
	{
		x = 800.0f;

		CObjmeteoL* obj = new CObjmeteoL(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);


	}
	if (m_time%530 == 0)
	{
		x = 400.0f;

		CObjmeteoL* obj = new CObjmeteoL(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time %550 == 0)
	{
		x = 700.0f;

		CObjmeteoL* obj = new CObjmeteoL(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjmeteoL* obj = new CObjmeteoL(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 20==0 ||m_time==500)
	{


		CObjAlien* obj = new CObjAlien(800.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 200);


	}

	//ボス
	if (m_time == 1500)
	{
		Audio::Stop(0);//0番曲をストップ
		Audio::Start(1);//1番曲をスタート
		x = 100;
		CObjBoss6* obj = new CObjBoss6(x, 10.0f);
		Objs::InsertObj(obj, OBJ_BOSS6, 13);
	}
}