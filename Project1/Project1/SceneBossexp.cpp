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

//�R���g���N�^
CSceneBossexp::CSceneBossexp(int c)
{
	Count =c;

	m_time = 0;
}

//�f�X�g���N�^
CSceneBossexp::~CSceneBossexp()
{

}

//�Q�[�����C�����������\�b�h
void CSceneBossexp::InitScene()
{
	Draw::LoadImage(L"hero.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"�{�X����.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"�c�w�i.png", 5, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);


	//�w�i
	CObjBackground* back = new CObjBackground();
	Objs::InsertObj(back, OBJ_BACKGROUND, 0);
}


//�Q�[�����C�����s�����\�b�h
void CSceneBossexp::Scene()
{
	m_time++;

	if (m_time == 10)
	{

		CObjBossima* obj = new CObjBossima(100,-150);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);

	}


	if (m_time == 50)
	{

		//�N���A�Ɉړ�
		Scene::SetScene(new CSceneClear(Count));

	}
}