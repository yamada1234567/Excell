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
#include "SceneGameOver.h"
#include "SceneMain.h"
#include "GameHead.h"

//�R���g���N�^
CSceneGameOver::CSceneGameOver(int c)
{
	C = c;
}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶�����O���t�B�b�N���쐬
	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"BGMGameOver.wav", BACK_MUSIC);

	//�{�����E�[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�Q�[���I�[�o�[�I�u�W�F�N�g���쐬
	CObjGameOver* obj = new CObjGameOver(C);
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);
}


//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{


}