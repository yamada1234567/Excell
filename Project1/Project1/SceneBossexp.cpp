
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"


using namespace GameL;


#include"SceneMain.h"
#include "SceneBossexp.h"
#include"GameHead.h"


CSceneBossexp::CSceneBossexp(int c)
{
	Count =c;

	m_time = 0;
}


CSceneBossexp::~CSceneBossexp()
{

}


void CSceneBossexp::InitScene()
{
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"É{ÉXîöî≠.png", 50, TEX_SIZE_512);
	Draw::LoadImage(L"ècîwåi.png", 5, TEX_SIZE_512);

	
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);


	
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);
}



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

		
		Scene::SetScene(new CSceneClear(Count));

	}
}