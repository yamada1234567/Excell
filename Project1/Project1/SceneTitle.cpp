
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]


#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL/DrawTexture.h"
#include "GameL/Audio.h"

using namespace GameL;


#include "SceneMain.h"
#include "GameHead.h"


CSceneTitle::CSceneTitle()
{

}


CSceneTitle::~CSceneTitle()
{

}


void CSceneTitle::InitScene()
{
	Draw::LoadImage(L"タイトル.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"操作方法.png", 2, TEX_SIZE_512);
	

	Audio::LoadAudio( 0 , L"BGMSceneTitle.wav", SOUND_TYPE::BACK_MUSIC);


	float Volume = Audio::VolumeMaster(-0.3f);
	Audio::Start(0); 



	CObjTitle* obj = new CObjTitle();   
	Objs::InsertObj(obj, OBJ_TITLE, 10);
}



void CSceneTitle::Scene()
{


}