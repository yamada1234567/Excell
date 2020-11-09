#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_TRIPLE,
	OBJ_meteoS,
	OBJ_meteoM,
	OBJ_meteoL,
	OBJ_meteoRD,
	OBJ_meteoLD,
	OBJ_meteoSIN,
	OBJ_Alien,
	OBJ_BOSS,
	OBJ_BOSS2,
	OBJ_BOSS3,
	OBJ_BOSS4,
	OBJ_BOSS5,
	OBJ_BOSS6,

	OBJ_BULLET,
	OBJ_TRIPLEBULLET,
	OBJ_TRIPLEBULLET2,

	OBJ_OXYGEN,
	OBJ_ITEM,
	OBJ_SHIELD,

	OBJ_BACKGROUND,

	OBJ_GAMEOVER,
	OBJ_TITLE,
	OBJ_CLEAR,

};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
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

};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "hero.h"
#include "bullet.h"
#include "triplebullet.h"
#include "triplebullet2.h"
#include "meteoS.h"
#include "meteoM.h"
#include "meteoL.h"
#include "meteoRD.h"
#include "meteoLD.h"
#include "meteoSin.h"
#include "Alien.h"
#include "Boss.h"
#include"Boss2.h"
#include"Boss3.h"
#include"Boss4.h"
#include"Boss5.h"
#include"Boss6.h"
#include "item.h"
#include "Oxygen.h"
#include "shield.h"
#include "ObjBackground.h"


#include "ObjGameOver.h"
#include "ObjTitle.h"
#include "ObjClear.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneStage2.h"
#include "SceneStage3.h"
#include "SceneStage4.h"
#include "SceneStage5.h"
#include "SceneLast.h"

#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
//sdsdfsfsfsdf
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneLast
//-----------------------------------------------