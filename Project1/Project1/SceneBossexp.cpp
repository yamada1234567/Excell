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
	Count =c;

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
	Draw::LoadImage(L"ボス爆発.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"縦背景.png", 5, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);


	//背景
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);
}


//ゲームメイン実行中メソッド
void CSceneBossexp::Scene()
{
	m_time++;

	if (m_time == 10)
	{

		CObjBossima* obj = new CObjBossima(100,-150);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);

	}


	if (m_time == 50)
	{

		//クリアに移動
		Scene::SetScene(new CSceneClear(Count));

	}
}