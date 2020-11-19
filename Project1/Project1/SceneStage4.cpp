//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneStage4.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneStage4::CSceneStage4()
{

}
//�f�X�g���N�^
CSceneStage4::~CSceneStage4()
{
	x = 0.0f;
	y = 0.0f;
}
//�Q�[�����C�����������\�b�h
void CSceneStage4::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"�c�w�i.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(Venus).png", 11, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);
	Draw::LoadImage(L"Shield.png", 8, TEX_SIZE_512);
	Draw::LoadImage(L"hero 1damage.png", 15, TEX_SIZE_512);
	Draw::LoadImage(L"hero 2damage.png", 16, TEX_SIZE_512);
	Draw::LoadImage(L"hero dead.png", 17, TEX_SIZE_512);
	Draw::LoadImage(L"UFO.png", 20, TEX_SIZE_512);
	Draw::LoadImage(L"barrier.png", 22, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero(4);//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 1);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�G���e�I
	//CObjmeteoRD* obj_meteoRD = new CObjmeteoRD(100, 100);
	//Objs::InsertObj(obj_meteoRD, OBJ_meteoRD, 4);

	//�w�i
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);


	m_time = 0;
}
//�Q�[�����C�����s���\�b�h
void CSceneStage4::Scene()
{
	m_time++;

	
	if (m_time % 500 == 0)
	{
		x = 0.0f;

		CObjAlien* obj = new CObjAlien(0.0f, 100.0f);
		Objs::InsertObj(obj, OBJ_Alien, 200);
	}
	//�o�͂��鎞��(time��50�ɂȂ�Əo��)
	if (m_time % 50 == 0)
	{
		//�E���ɐi��覐Ώo��
		CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoRD, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//�o�͂��鎞��(time��50�ɂȂ�Əo��)
	if (m_time % 50 == 0)
	{
		//�����ɐi��覐Ώo��
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}

	//�o�͂��鎞��(time��60�ɂȂ�Əo��)
	if (m_time % 60 == 0)
	{
		//S���ɐi��覐Ώo��
		CObjmeteoSin* obj = new CObjmeteoSin(368.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoSIN, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	
	//�o�͂��鎞��(time��50�ɂȂ�Əo��)
	if (m_time % 70 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(290.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}

	//�o�͂��鎞��(time��40�ɂȂ�Əo��)
	if (m_time % 66 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(460.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 83 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(400.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 67 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(110.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 55 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(330.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 50 == 0)
	{
		//��覐Ώo��
		CObjmeteoS* obj = new CObjmeteoS(670.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoS, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//�o�͂��鎞��(time��60�ɂȂ�Əo��)
	if (m_time % 70 == 0)
	{
		//��覐Ώo��
		CObjmeteoM* obj = new CObjmeteoM(70.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 100 == 0)
	{
		//��覐Ώo��
		CObjmeteoM* obj = new CObjmeteoM(610.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 90 == 0)
	{
		//��覐Ώo��
		CObjmeteoM* obj = new CObjmeteoM(390.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoM, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	//�o�͂��鎞��(time��70�ɂȂ�Əo��)
	if (m_time % 88 == 0)
	{
		//��覐Ώo��
		CObjmeteoL* obj = new CObjmeteoL(300.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 80 == 0)
	{
		//��覐Ώo��
		CObjmeteoL* obj = new CObjmeteoL(700.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	if (m_time % 60 == 0)
	{
		//��覐Ώo��
		CObjmeteoL* obj = new CObjmeteoL(0.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoL, 4);
		obj->SetVector(0.0f, 1.0f);
	}
	
	//�o�͂��鎞��(time��500�ɂȂ�Əo��)
	if (m_time == 1500)
	{
		//�{�X�o��
		CObjBoss4* obj = new CObjBoss4(100.0f, 10.0f);
		Objs::InsertObj(obj, OBJ_BOSS4, 13);
	}
}