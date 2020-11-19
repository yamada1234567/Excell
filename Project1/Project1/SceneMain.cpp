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
#include"SceneMain.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain::CSceneMain()
{
	x = 0.0f;
	y = 0.0f;
}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}
//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMSceneMain.wav",BACK_MUSIC);
	Audio::LoadAudio(1, L"BGMBoss.wav", BACK_MUSIC);

	Audio::LoadAudio(2, L"SEbullet.wav", EFFECT);
	Audio::LoadAudio(3, L"SEEnemyexp.wav",EFFECT);
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
	Draw::LoadImage(L"Boss(moon).png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);
	Draw::LoadImage(L"覐Δ���.png", 50, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(1);//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj,OBJ_HERO,1);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^




	//�w�i
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);

	m_time = 0;
}
//�Q�[�����C�����s���\�b�h
void CSceneMain::Scene()
{
	
	//�N���A�Ɉړ�
	//Scene::SetScene(new CSceneClear());
	Scene::SetScene(new CSceneClear(4));
	


	//����
	m_time++;

	if (m_time %500 == 0)
	{

		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 20);
	}
	if (m_time % 63 == 0)
	{
		x = 200.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 65 == 0)
	{
		x = 100.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 58 == 0)
	{
		x = 150.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 70 == 0)
	{
		x = 300.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 50 == 0)
	{
		x = 450.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 77 == 0)
	{
		x = 580.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 55 == 0)
	{
		x = 640.0f;

		CObjmeteoS* obj = new CObjmeteoS(x, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time == 1200)
	{
		//���y�`�F���W
		Audio::Stop(0);//0�ԋȂ��X�g�b�v
		Audio::Start(1);//1�ԋȂ��X�^�[�g

		x = 100;
		CObjBoss* obj = new CObjBoss(x, -640.0f);
		Objs::InsertObj(obj, OBJ_BOSS, 6);
	}
}