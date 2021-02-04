
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)


#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"


using namespace GameL;


#include"SceneStage4.h"
#include"GameHead.h"
#include <stdlib.h>
#include <time.h>

CSceneStage4::CSceneStage4()
{
	m_time = 0;
	x = 0.0f;
	y = 0.0f;
}

CSceneStage4::~CSceneStage4()
{

}
void CSceneStage4::InitScene()
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
	Draw::LoadImage(L"Boss(Venus).png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);
	Draw::LoadImage(L"Ë¶êŒîöî≠.png", 50, TEX_SIZE_512);
	Draw::LoadImage(L"BOOM.png", 23, TEX_SIZE_512);
	Draw::LoadImage(L"bomb.png", 24, TEX_SIZE_512);
	CObjHero* obj = new CObjHero(4);
	Objs::InsertObj(obj, OBJ_HERO, 1);




	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

}

void CSceneStage4::Scene()
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
		Objs::InsertObj(obj, OBJ_Alien, 200);
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
			x = 450.0f;
		}
		else if (pos == 2)
		{
			x = 630.0f;
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
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjmeteoL* obj = new CObjmeteoL(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				CObjmeteoM* obj = new CObjmeteoM(x - a, -100.0f + a);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 6)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f + a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 5)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f+a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f + a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjO2meteo* obj = new CObjO2meteo(x + a, -100.0f + a);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x + a, -100.0f + a);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 1)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 2)
			{
				CObjmeteoM* obj = new CObjmeteoM(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 66)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 3)
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
			else if (random == 0)
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
			else if (random == 2)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 80)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 2)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
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
				CObjO2meteo* obj = new CObjO2meteo(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
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
		if (m_time == i * 80)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 0)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjO2meteo* obj = new CObjO2meteo(x, -100.0f);
				Objs::InsertObj(obj, OBJ_O2meteo, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 2)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (m_time == i * 120)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 6;
			if (random == 3)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 20.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 20.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			if (random == 4)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 150.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 5)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 150.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			if (random == 1)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 300.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 2)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 300.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
		}
	}

	if (m_time == 1500)
	{
	
		Audio::Stop(0);
		Audio::Start(1);
	
		CObjBoss4* obj = new CObjBoss4(-100.0f, -630.0f);
		Objs::InsertObj(obj, OBJ_BOSS4, 11);
	}
}