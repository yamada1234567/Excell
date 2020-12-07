//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"
#include"GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneLast.h"
#include"GameHead.h"
#include <stdlib.h>
#include <time.h>
//�R���X�g���N�^
CSceneLast::CSceneLast()
{

}
//�f�X�g���N�^
CSceneLast::~CSceneLast()
{
	x = 0.0f;
	y = 0.0f;


}
//�Q�[�����C�����������\�b�h
void CSceneLast::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMSceneMain.wav", BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMLastBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SEbullet.wav", EFFECT);
	Audio::LoadAudio(3, L"SEEnemyexp.wav", EFFECT);
	Audio::LoadAudio(4, L"SEheroexp.wav", EFFECT);

	//�{�����[����1.5���₷
	float v = Audio::VolumeMaster(1.5);

	//���y�X�^�[�g
	Audio::Start(0);

	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"�c�w�i.png", 5, TEX_SIZE_512);
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
	Draw::LoadImage(L"覐Δ���.png", 50, TEX_SIZE_512);
	Draw::LoadImage(L"BOOM.png", 23, TEX_SIZE_512);
	Draw::LoadImage(L"bomb.png", 24, TEX_SIZE_512);
	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(6);//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 1);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^


	//�w�i
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);


	m_time = 0;
}
//�Q�[�����C�����s���\�b�h
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

	for (int i = 0; i < 10000; i++)//�����_��覐�
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

	for (int i = 0; i < 10000; i++)//�����_��覐�
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
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				CObjmeteoM* obj = new CObjmeteoM(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}

	for (int i = 0; i < 10000; i++)//�����_��覐�2
	{
		if (m_time == i * 80)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 7)
			{
				CObjmeteoS* obj = new CObjmeteoS(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
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
				CObjmeteoL* obj = new CObjmeteoL(x - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				Objs::InsertObj(obj, OBJ_meteoS, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 2)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(x, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}

	for (int i = 0; i < 10000; i++)//�����_��覐�2
	{
		if (m_time == i * 45)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 8;
			if (random == 6)
			{
				CObjmeteoS* obj = new CObjmeteoS(400.0f - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 0)
			{
				CObjmeteoM* obj = new CObjmeteoM(400.0f - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 7)
			{
				CObjmeteoL* obj = new CObjmeteoL(400.0f - a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 5)
			{
				CObjmeteoS* obj = new CObjmeteoS(400.0f + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 2)
			{
				CObjmeteoM* obj = new CObjmeteoM(400.0f + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 4)
			{
				CObjmeteoS* obj = new CObjmeteoS(400.0f + a, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 2);
				obj->SetVector(0.0f, 1.0f);
			}
			if (random == 3)
			{
				CObjmeteoS* obj = new CObjmeteoS(400.0f, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoS, 4);
				obj->SetVector(0.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoS* obj = new CObjmeteoS(400.0f, -100.0f);
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}
	for (int i = 0; i < 10000; i++)//�����_��覐�
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
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				CObjmeteoM* obj = new CObjmeteoM(x + a, -100.0f - a);
				Objs::InsertObj(obj, OBJ_meteoL, 2);
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
				Objs::InsertObj(obj, OBJ_meteoM, 3);
				obj->SetVector(0.0f, 1.0f);
			}
		}
	}

	for (int i = 0; i < 10000; i++)//�����_��覐Ύ΂�
	{
		if (m_time == i * 100)
		{
			random = 0;
			srand((int)time(NULL));
			random = rand() % 6;
			if (random == 0)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 20.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 1)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 20.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			if (random == 2)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 150.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 3)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 150.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			if (random == 4)
			{
				CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 300.0f);
				Objs::InsertObj(obj, OBJ_meteoRD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
			else if (random == 6)
			{
				CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 300.0f);
				Objs::InsertObj(obj, OBJ_meteoLD, 4);
				obj->SetVector(1.0f, 1.0f);
			}
		}
	}

	for (int i = 0; i < 10000; i++)//�����_��覐Ύ΂߂Q
	{
		if (m_time == i * 50)
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

	//�{�X
	if (m_time == 1500)
	{
		Audio::Stop(0);//0�ԋȂ��X�g�b�v
		Audio::Start(1);//1�ԋȂ��X�^�[�g
		x = 100;
		CObjBoss6* obj = new CObjBoss6(x, -660.0f);
		Objs::InsertObj(obj, OBJ_BOSS6, 13);
	}
}