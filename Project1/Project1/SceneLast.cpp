//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneLast.h"
#include"GameHead.h"
//コンストラクタ
CSceneLast::CSceneLast()
{

}
//デストラクタ
CSceneLast::~CSceneLast()
{
	x = 0;
	y = 0;

}
//ゲームメイン初期化メソッド
void CSceneLast::InitScene()
{
	//外部グラフィックファイルを読み込む0番に登録()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(moon).png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();//主人公オブジェクト作成
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


	if (m_time % 100 == 0)
	{
		y+=20.0f;
		if (y >= 100)
		{
			y = 0.0;
		}										//60
		CObjmeteoRD* obj = new CObjmeteoRD(0.0f, y);
		Objs::InsertObj(obj, OBJ_meteoRD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
	if (m_time % 100 == 0)
	{
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
	if (m_time % 50 == 0)
	{
		x+=1.0f;
		if (x >= 800)
		{
			x = 0.0;
		}
			CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
			Objs::InsertObj(obj, OBJ_meteoS, 4);
			obj->SetVector(0.0f, 1.0f);
	

	}
	//if (m_time == 200)
	//{
	//	//クリアに移動
	//	Scene::SetScene(new CSceneClear(5));
	//}
}