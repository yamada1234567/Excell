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
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	Font::SetStrTex(L"���߂łƂ��I");
	Font::SetStrTex(L"���̃X�e�[�W�ɐi��");

	CObjClear* obj = new CObjClear();
	Objs::InsertObj(obj, OBJ_CLEAR, 10);

}


//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{


}