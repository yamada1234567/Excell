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
	Count = c;

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
	Draw::LoadImage(L"覐Δ���.png", 50, TEX_SIZE_512);


	//��l���I�u�W�F�N�g�쐬
	CObjHeroime* obj = new CObjHeroime();
	Objs::InsertObj(obj, OBJ_HEROIME, 1);



}


//�Q�[�����C�����s�����\�b�h
void CSceneBossexp::Scene()
{
	m_time++;

	if (m_time == 10)
	{

		CObjBossima* obj = new CObjBossima(350,100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	
	if (m_time == 30)
	{
		CObjBossima* obj = new CObjBossima(300, 60);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 50)
	{
		CObjBossima* obj = new CObjBossima(360, 130);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 60)
	{
		CObjBossima* obj = new CObjBossima(300, 160);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 70)
	{
		CObjBossima* obj = new CObjBossima(400, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 80)
	{
		CObjBossima* obj = new CObjBossima(350, 60);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 90)
	{
		CObjBossima* obj = new CObjBossima(300, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 100)
	{
		CObjBossima* obj = new CObjBossima(320, 150);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 120)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 130)
	{
		CObjBossima* obj = new CObjBossima(390, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 140)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 150)
	{
		CObjBossima* obj = new CObjBossima(390, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 160)
	{
		CObjBossima* obj = new CObjBossima(30, 100);
		Objs::InsertObj(obj, OBJ_BOSSIMA, 50);
	}
	if (m_time == 200)
	{

		//�N���A�Ɉړ�
		Scene::SetScene(new CSceneClear(Count));

	}
}