#pragma once


enum OBJ_NAME
{
	OBJ_NO_NAME,	


	OBJ_HERO,
	OBJ_TRIPLE,
	OBJ_BOM,
	OBJ_DIFFUSION,

	OBJ_meteoS,
	OBJ_meteoM,
	OBJ_meteoL,
	OBJ_meteoRD,
	OBJ_meteoLD,
	OBJ_meteoSIN,
	OBJ_O2meteo,
	OBJ_Alien,
	OBJ_BOSS,
	OBJ_BOSS2,
	OBJ_BOSS3,
	OBJ_BOSS4,
	OBJ_BOSS5,
	OBJ_BOSS6,

	OBJ_BULLET,
	OBJ_BOM_BULLET,

	OBJ_OXYGEN,
	OBJ_ITEM,
	OBJ_SHIELD,
	OBJ_BOMB,

	OBJ_BACKGROUND,

	OBJ_GAMEOVER,
	OBJ_TITLE,
	OBJ_CLEAR,
	OBJ_DES,

	OBJ_HEROIME,
	OBJ_BOSSIMA,
};



enum HIT_ELEMENTS
{
	ELEMENT_NULL,

	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_OXYGEN,
	ELEMENT_SHIELD,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_BULLET,
	ELEMENT_EXPLOSION,

};




struct UserData
{
	int mSeveData;	
	
};

#include "hero.h"
#include "bullet.h"
#include "BomBullet.h"
#include "Bom.h"
#include "Diffusion.h"



#include "meteoS.h"
#include "meteoM.h"
#include "meteoL.h"
#include "meteoRD.h"
#include "meteoLD.h"
#include "meteoSin.h"
#include "O2meteo.h"
#include "Alien.h"
#include "Boss.h"
#include "Boss2.h"
#include "Boss3.h"
#include "Boss4.h"
#include "Boss5.h"
#include "Boss6.h"
#include "bossima.h"

#include "item.h"
#include "Oxygen.h"
#include "shield.h"
#include "ObjBackground.h"
#include "Bomb.h"

#include "ObjGameOver.h"
#include "ObjTitle.h"
#include "ObjClear.h"
#include "ObjDes.h"

#include "heroima.h"



#include "SceneMain.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneLast.h"
#include "SceneBossexp.h"

#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
#include "SceneDes.h"


#define SET_GAME_START CSceneTitle
