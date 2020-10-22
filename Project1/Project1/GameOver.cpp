//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

//GameL�Ŏg�p����w�b�_�[
#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "GameOver.h"

//�R���g���N�^
GameOver::GameOver()
{

}

//�f�X�g���N�^
GameOver::~GameOver()
{

}

//�Q�[�����C�����������\�b�h
void GameOver::InitScene()
{
	//�o�͂����镶�����O���t�B�b�N���쐬
	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");


	//�Q�[���I�[�o�[�I�u�W�F�N�g���쐬
	GameOver* obj = new GameOver();
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);
}


//�Q�[�����C�����s�����\�b�h
void GameOver::Scene()
{


}