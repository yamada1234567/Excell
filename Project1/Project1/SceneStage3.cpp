
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"

using namespace GameL;


#include"SceneStage3.h"
#include"GameHead.h"
#include <stdlib.h>
#include <time.h>

CSceneStage3::CSceneStage3()
{

}

CSceneStage3::~CSceneStage3()
{
	x = 0.0f;
	y = 0.0f;
}

void CSceneStage3::InitScene()
{

	
	Audio::LoadAudio(0, L"BGMSceneMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SEbullet.wav", EFFECT);
	Audio::LoadAudio(3, L"SEEnemyexp.wav", EFFECT);
	Audio::LoadAudio(4, L"SEheroexp.wav", EFFECT);

	
	float v = Audio::VolumeMaster(1.5);

	
	Audio::Start(0);

	
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"ècîwåi.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(jupiter).png", 10, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);
	Draw::LoadImage(L"Ë¶êŒîöî≠.png", 50, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"BOOM.png", 23, TEX_SIZE_512);
	Draw::LoadImage(L"bomb.png", 24, TEX_SIZE_512);

	
	CObjHero* obj = new CObjHero(3);
	Objs::InsertObj(obj, OBJ_HERO, 1);

	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);


	m_time = 0;
}

void CSceneStage3::Scene()
{
	
	m_time++;
	int random;
	int pos;
	int pos2;
	int x;
	int a;

	if (m_time % 600 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 20);
	}
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
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 60)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 0)
			{
				CObjmeteoL* obj = new CObjmeteoL(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				CObjmeteoM* obj = new CObjmeteoM(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjO2meteo* obj = new CObjO2meteo(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoL* obj = new CObjmeteoL(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 5)
			{
				CObjmeteoM* obj = new CObjmeteoM(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
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
				CObjmeteoM* obj = new CObjmeteoM(x, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 63)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 7)
			{
				CObjmeteoL* obj = new CObjmeteoL(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 5)
			{
				CObjmeteoM* obj = new CObjmeteoM(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 6)
			{
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoM* obj = new CObjmeteoM(x + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 2)
			{
				CObjmeteoM* obj = new CObjmeteoM(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoM* obj = new CObjmeteoM(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 30)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 2)
			{
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 50)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 2)
			{
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 50)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 2)
			{
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}

	
	if (m_time == 1300)
	{
		
		Audio::Stop(0);
		Audio::Start(1);
	
		CObjBoss3* obj = new CObjBoss3(-100.0f, -650.0f);
		Objs::InsertObj(obj, OBJ_BOSS3, 10);
	}

}