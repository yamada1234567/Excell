//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"

//�R���g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//�Q�[�����C�����������\�b�h
void CSceneClear::InitScene()
{


	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

}


//�Q�[�����C�����s�����\�b�h
void CSceneClear::Scene()
{


}