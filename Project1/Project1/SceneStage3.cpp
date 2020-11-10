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
void CSceneStage3::Scene()
{
	//時間
	m_time++;
 
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

	//出力する時間(timeが100になると出力)
	if (m_time %100==0)
	{
		//中隕石出力
		CObjmeteoM* obj = new CObjmeteoM(500.0f, -100.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 3);
		obj->SetVector(0.0f, 1.0f);
	}

	//出力する時間(timeが60になると出力)
	if (m_time % 120 == 0)
	{

			CObjmeteoM* obj = new CObjmeteoM(100.0f, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoM, 4);
			obj->SetVector(0.0f, 1.0f);

	}

	if (m_time==200 || m_time == 500 ||m_time==800)
	{

		CObjmeteoL* obj = new CObjmeteoL(300.0f, 0.0f);
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
	if (m_time == 1500)
	{
		//ボス出力
		CObjBoss3* obj = new CObjBoss3(100.0f, 10.0f);
		Objs::InsertObj(obj, OBJ_BOSS3, 13);
	}

}