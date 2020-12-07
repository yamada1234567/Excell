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
#include"SceneMain.h"
#include "SceneBossexp.h"
#include"GameHead.h"

//コントラクタ
CSceneBossexp::CSceneBossexp(int c)
{
	Count = c;

	m_time = 0;
}

//デストラクタ
CSceneBossexp::~CSceneBossexp()
{

}

//ゲームメイン初期化メソッド
void CSceneBossexp::InitScene()
{
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"隕石爆発.png", 50, TEX_SIZE_512);


	//主人公オブジェクト作成
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);



}


//ゲームメイン実行中メソッド
void CSceneBossexp::Scene()
{
	m_time++;

	if (m_time == 10)
	{

		CObjBossima* obj = new CObjBossima(350,100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	
	if (m_time == 30)
	{
		CObjBossima* obj = new CObjBossima(300, 60);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 50)
	{
		CObjBossima* obj = new CObjBossima(360, 130);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 60)
	{
		CObjBossima* obj = new CObjBossima(300, 160);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 70)
	{
		CObjBossima* obj = new CObjBossima(400, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 80)
	{
		CObjBossima* obj = new CObjBossima(350, 60);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 90)
	{
		CObjBossima* obj = new CObjBossima(300, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 100)
	{
		CObjBossima* obj = new CObjBossima(320, 150);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 120)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 130)
	{
		CObjBossima* obj = new CObjBossima(390, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 140)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 150)
	{
		CObjBossima* obj = new CObjBossima(390, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 160)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 200)
	{

		//クリアに移動
		Scene::SetScene(new CSceneClear(Count));

	}
}