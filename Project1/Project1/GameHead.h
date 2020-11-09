#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
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

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
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
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_------------------
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

//�Q�[���V�[���N���X�w�b�_------------------------
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

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneLast
//-----------------------------------------------