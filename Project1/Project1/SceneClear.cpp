//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"

//�R���g���N�^
CSceneClear::CSceneClear(int Cou)
{
	Count = Cou;
}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�Q�[�����C�����������\�b�h
void CSceneClear::InitScene()
{
	if(Count==7)
	{
	CObjClear* obj = new CObjClear(Count);
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMSceneLast.wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//���y�X�^�[�g
	Audio::Start(0);

	}
	else
	{
		CObjClear* obj = new CObjClear(Count);
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

		//���y�ǂݍ���
		Audio::LoadAudio(0, L"BGMSceneClear.wav", BACK_MUSIC);

		//�{�����[����1.0�ɖ߂�
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster(1.0 - v);

		//���y�X�^�[�g
		Audio::Start(0);
	}
}


//�Q�[�����C�����s�����\�b�h
void CSceneClear::Scene()
{


}