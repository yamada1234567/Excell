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
#include "SceneBossexp.h"
#include"GameHead.h"
#include <stdlib.h>
#include <time.h>

//�R���g���N�^
CSceneBossexp::CSceneBossexp()
{

}

//�f�X�g���N�^
CSceneBossexp::~CSceneBossexp()
{

}

//�Q�[�����C�����������\�b�h
void CSceneBossexp::InitScene()
{
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);


	//��l���I�u�W�F�N�g�쐬
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);




}


//�Q�[�����C�����s�����\�b�h
void CSceneBossexp::Scene()
{


}