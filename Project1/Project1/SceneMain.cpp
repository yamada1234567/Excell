//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL/DrawTexture.h"
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"
//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}
//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^()
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"hero bullet.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"meteoS.png", 2, TEX_SIZE_512);
	//Draw::LoadImage(L"triple.png", 3, TEX_SIZE_512);
	//Draw::LoadImage(L"meteoS.png", 4, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj,OBJ_HERO,1);//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//�G���e�I
	CObjmeteoS* obj_meteoS = new CObjmeteoS(100,100);
	Objs::InsertObj(obj_meteoS, OBJ_meteoS, 4);

	//�G���e�I
	CObjmeteoM* obj_meteoM = new CObjmeteoM(100, 100);
	Objs::InsertObj(obj_meteoM, OBJ_meteoM, 3);
	
	//�G���e�I
	CObjmeteoL* obj_meteoL = new CObjmeteoL(100, 100);
	Objs::InsertObj(obj_meteoL, OBJ_meteoL, 2);

	//�A�C�e��
	//CObjitem* obj_item = new CObjitem(100, 100);
	//Objs::InsertObj(obj_item, OBJ_ITEM, 5);
	
	//�{�X
	/*CObjBoss* obj_Boss = new CObjBoss(300, 120);
	Objs::InsertObj(obj_meteoS, OBJ_BOSS, 4);*/


}
//�Q�[�����C�����s���\�b�h
void CSceneMain::Scene()
{
	
}