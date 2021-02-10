#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]

#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL/DrawTexture.h"
#include "GameL/Audio.h"

using namespace GameL;

#include "SceneMain.h"
#include "GameHead.h"


CSceneDes::CSceneDes()
{

}


CSceneDes::~CSceneDes()
{

}


void CSceneDes::InitScene()
{

	Audio::LoadAudio(0, L"BGMSceneTitle.wav", SOUND_TYPE::BACK_MUSIC);


	float Volume = Audio::VolumeMaster(-0.3f);
	Audio::Start(0);


	Draw::LoadImage(L"ëÄçÏï˚ñ@.png", 1, TEX_SIZE_512);

	CObjDes* obj = new CObjDes();   
	Objs::InsertObj(obj, OBJ_DES, 10);
}

void CSceneDes::Scene()
{


}