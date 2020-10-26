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
	//Draw::LoadImage(L"meteoS.png", 4, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
	Objs::InsertObj(obj,OBJ_HERO,1);//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//敵メテオ
	//CObjmeteoS* obj_meteoS = new CObjmeteoS(100,100);
	//Objs::InsertObj(obj_meteoS, OBJ_meteoS, 4);

	//敵メテオ
	//CObjmeteoM* obj_meteoM = new CObjmeteoM(100, 100);
	//Objs::InsertObj(obj_meteoM, OBJ_meteoM, 3);
	
	//敵メテオ
	//CObjmeteoL* obj_meteoL = new CObjmeteoL(100, 100);
	//Objs::InsertObj(obj_meteoL, OBJ_meteoL, 2);

	//アイテム
	//CObjitem* obj_item = new CObjitem(100, 100);
	//Objs::InsertObj(obj_item, OBJ_ITEM, 5);
	
	//ボス
	/*CObjBoss* obj_Boss = new CObjBoss(300, 120);
	Objs::InsertObj(obj_meteoS, OBJ_BOSS, 4);*/

	//背景
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	m_time = 0;
}
//ゲームメイン実行メソッド
void CSceneMain::Scene()
{
	m_time++;
	if (m_time == 30)
	{
		CObjmeteoS* obj = new CObjmeteoS(400.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 80)
	{
		CObjmeteoM* obj = new CObjmeteoM(500.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);

	}
	else if (m_time == 120)
	{
		CObjmeteoL* obj = new CObjmeteoL(300.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoL, 2);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 150)
	{
		CObjmeteoM* obj = new CObjmeteoM(330.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);

	}
	else if (m_time == 180)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(220.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(350.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 190)
	{
		CObjmeteoM* obj = new CObjmeteoM(590.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);

	}
	else if (m_time == 200)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(260.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(160.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 210)
	{
		CObjmeteoM* obj = new CObjmeteoM(550.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);

	}
	else if (m_time == 230)
	{
		CObjmeteoL* obj = new CObjmeteoL(370.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoL, 2);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 250)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(220.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(540.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 300)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(120.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(420.0f, 100);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 380)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(370.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(430.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 400)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(310.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(460.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 430)
	{
	CObjmeteoL* obj = new CObjmeteoL(320.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoL, 2);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 460)
	{
	CObjmeteoM* obj = new CObjmeteoM(350.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoM, 3);
	obj->SetVector(0.0f, 1.0f);

	}
	else if (m_time == 480)
	{
	CObjmeteoS* obj;
	obj = new CObjmeteoS(254.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoS(452.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 550)
	{
		CObjmeteoM* obj;
		obj = new CObjmeteoM(280.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
		obj= new CObjmeteoM(150.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 580)
	{
	CObjmeteoS* obj;
	obj = new CObjmeteoS(250.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoS(450.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 620)
	{
	CObjmeteoS* obj;
	obj = new CObjmeteoS(490.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoS(550.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 680)
	{
		CObjmeteoL* obj;
		obj = new CObjmeteoL(240.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoL, 2);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoL(490.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoL, 2);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 690)
	{
	CObjmeteoM* obj;
	obj = new CObjmeteoM(280.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoM, 3);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoM(190.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoM, 3);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 700)
	{
	CObjmeteoS* obj;
	obj = new CObjmeteoS(400.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoS(550.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 750)
	{
		CObjmeteoM* obj;
		obj = new CObjmeteoM(260.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 790)
	{
	CObjmeteoM* obj;
	obj = new CObjmeteoM(200.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoM, 3);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1000)
	{
		CObjmeteoM* obj;
		obj = new CObjmeteoM(259.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoM(190.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		CObjmeteoS* obj1;
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1100)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(490.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoS(410.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1200)
	{
		CObjmeteoS* obj;
		obj = new CObjmeteoS(590.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
		obj= new CObjmeteoS(190.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1300)
	{
		CObjmeteoM* obj;
		obj = new CObjmeteoM(480.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoM(240.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1400)
	{
	CObjmeteoS* obj;
	obj = new CObjmeteoS(290.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	obj = new CObjmeteoS(490.0f, 0);
	Objs::InsertObj(obj, OBJ_meteoS, 4);
	obj->SetVector(0.0f, 1.0f);
	}
	else if (m_time == 1500)
	{
		CObjmeteoM* obj;
		obj = new CObjmeteoM(510.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
		obj = new CObjmeteoM(160.0f, 0);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
	}
}