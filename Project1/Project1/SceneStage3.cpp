//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneStage3.h"
#include"GameHead.h"
//コンストラクタ
CSceneStage3::CSceneStage3()
{

}
//デストラクタ
CSceneStage3::~CSceneStage3()
{
	x = 0.0f;
	y = 0.0f;
}
//ゲームメイン初期化メソッド
void CSceneStage3::InitScene()
{
	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(jupiter).png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);

	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero(3);//主人公オブジェクト作成
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
void CSceneStage3::Scene()
{
	//時間
	m_time++;
 
	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 200);
	}
	if(m_time % 50 == 0)
	{	

		if (m_time%2==1)
		{
			CObjmeteoM* obj = new CObjmeteoM(100.0f, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoM, 4);
			obj->SetVector(0.0f, 1.0f);

		}
		else
		{

			CObjmeteoS* obj = new CObjmeteoS(500.0f, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoS, 4);
			obj->SetVector(0.0f, 1.0f);

		}

	}



	//出力する時間(timeが60になると出力)
	if (m_time% 60== 0)
	{
		//小隕石出力					座標 ｘ,ｙ
		CObjmeteoS* obj = new CObjmeteoS(368.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 50 == 0)
	{
		//小隕石出力					座標 ｘ,ｙ
		CObjmeteoS* obj = new CObjmeteoS(150.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 55 == 0)
	{
		//小隕石出力					座標 ｘ,ｙ
		CObjmeteoS* obj = new CObjmeteoS(330.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 60 == 0)
	{
		//小隕石出力					座標 ｘ,ｙ
		CObjmeteoS* obj = new CObjmeteoS(550.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}

	//出力する時間(timeが100になると出力)
	if (m_time %100==0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(500.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 150 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(220.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 160 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(350.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 170 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(280.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if(m_time % 120 == 0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(450.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}

	//出力する時間(timeが60になると出力)
	if (m_time % 120 == 0)
	{

			CObjmeteoM* obj = new CObjmeteoM(100.0f, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoM, 4);
			obj->SetVector(0.0f, 1.0f);

	}

	if (m_time==200 || m_time == 400 ||m_time==600)
	{

		CObjmeteoL* obj = new CObjmeteoL(500.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 200 || m_time == 300 || m_time == 500)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	//左大隕石
	if (m_time == 200 || m_time == 400|| m_time == 550)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 650 || m_time == 750 || m_time == 850)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 950 || m_time == 1150 || m_time == 1350)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 1450 || m_time == 1650 || m_time == 1750)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 1850 || m_time == 1950 || m_time == 2150)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 2250 || m_time == 2350 || m_time == 2450)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 2650 || m_time == 2750 || m_time == 2850)
	{

		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	//右大隕石
	if (m_time == 650 || m_time == 750 || m_time == 850)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 950 || m_time == 1150 || m_time == 1350)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 1450 || m_time == 1650 || m_time == 1750)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 1850 || m_time == 1950 || m_time == 2150)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 2250 || m_time == 2350 || m_time == 2450)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	if (m_time == 2650 || m_time == 2750 || m_time == 2850)
	{

		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);

	}
	//出力する時間(timeが50になると出力)
	if (m_time%130 == 0)
	{
		//右下に進む隕石出力　　　　　　  	
		CObjmeteoS* obj = new CObjmeteoS(60.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//出力する時間(timeが50になると出力)
	if (m_time% 200== 0)
	{
		//左下に進む隕石出力
		CObjmeteoS* obj = new CObjmeteoS(400.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//出力する時間(timeが200になると出力)
	if (m_time == 1600)
	{
		//ボス出力
		CObjBoss3* obj = new CObjBoss3(-100.0f, -650.0f);
		Objs::InsertObj(obj, OBJ_BOSS3, 10);
	}

}