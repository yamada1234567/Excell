//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneStage2.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneStage2::CSceneStage2()
{

}
//�f�X�g���N�^
CSceneStage2::~CSceneStage2()
{

}
//�Q�[�����C�����������\�b�h
void CSceneStage2::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"�c�w�i.png", 5, TEX_SIZE_512);
	Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"Boss(moon).png", 6, TEX_SIZE_512);
	Draw::LoadImage(L"Oxygen.png", 7, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();//��l���I�u�W�F�N�g�쐬
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
void CSceneStage2::Scene()
{
	m_time++;

	if (m_time % 50 == 0)
	{
		CObjmeteoRD* obj = new CObjmeteoRD(0.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoRD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
	if (m_time%50==0)
	{
		CObjmeteoLD* obj = new CObjmeteoLD(800.0f, 60.0f);
		Objs::InsertObj(obj, OBJ_meteoLD, 4);
		obj->SetVector(1.0f, 1.0f);
	}
	if (m_time%60 == 0)
	{
		CObjmeteoSin* obj = new CObjmeteoSin(368.0f, 0.0f);
		Objs::InsertObj(obj, OBJ_meteoSIN, 4);
		obj->SetVector(0.0f, 1.0f);
	}

}