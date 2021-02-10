
#define _SECURE_SCL	(0)  
#define _HAS_ITERATOR_DEBUGGING	(0)]


#include "GameL/SceneObjManager.h"
#include "GameL/DrawFont.h"
#include"GameL\Audio.h"



using namespace GameL;


#include "SceneGameOver.h"
#include "SceneMain.h"
#include "GameHead.h"


CSceneGameOver::CSceneGameOver(int c)
{
	C = c;
}


CSceneGameOver::~CSceneGameOver()
{

}


void CSceneGameOver::InitScene()
{

	Font::SetStrTex(L"YOU LOST");
	Font::SetStrTex(L"GAME OVER");
	Font::SetStrTex(L"NEXT_CHALLENGE:ENTER_KEY");


	Audio::LoadAudio(0, L"BGMSceneGameOver.wav", BACK_MUSIC);


	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1 - v));


	Audio::Start(0);


	CObjGameOver* obj = new CObjGameOver(C);
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);
}



void CSceneGameOver::Scene()
{


}