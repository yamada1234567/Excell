//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL/DrawTexture.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneDes::CSceneDes()
{

}

//�f�X�g���N�^
CSceneDes::~CSceneDes()
{

}

//�Q�[�����C�����������\�b�h
void CSceneDes::Scene()
{
	Draw::LoadImage(L"�^�C�g��.png", 1, TEX_SIZE_512);


	//���y�ǂݍ���
	//Audio::LoadAudio(0, L"BGMSceneTitle.wav", SOUND_TYPE::BACK_MUSIC);

	////�o�b�N�~���[�W�b�N�X�^�[�g
	//float Volume = Audio::VolumeMaster(-0.3f); //�}�X�^�[�{�����[����0.8������
	//Audio::Start(0);  //���y�X�^�[�g


	//�^�C�g���I�u�W�F�N�g���쐬
	CObjTitle* obj = new CObjTitle();   //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g�o�^
}


//�Q�[�����C�����s�����\�b�h
void CSceneDes::Scene()
{


}