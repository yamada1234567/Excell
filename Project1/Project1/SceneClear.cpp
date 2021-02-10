
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]


#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\Audio.h"
#include"GameL/DrawTexture.h"


using namespace GameL;


#include "SceneClear.h"
#include "GameHead.h"


CSceneClear::CSceneClear(int Cou)
{
	Count = Cou;
}


CSceneClear::~CSceneClear()
{

}


void CSceneClear::InitScene()
{
	Draw::LoadImage(L"ÉNÉäÉA.png", 1, TEX_SIZE_512);

	if(Count==7)
	{
	CObjClear* obj = new CObjClear(Count);
	Objs::InsertObj(obj, OBJ_CLEAR, 10);


	Audio::LoadAudio(0, L"BGMSceneLast.wav", BACK_MUSIC);


	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1 - v);


	Audio::Start(0);

	}
	else
	{
		CObjClear* obj = new CObjClear(Count);
		Objs::InsertObj(obj, OBJ_CLEAR, 10);

	
		Audio::LoadAudio(0, L"BGMSceneClear.wav", BACK_MUSIC);


		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster(1 - v);


		Audio::Start(0);
	}
}



void CSceneClear::Scene()
{


}