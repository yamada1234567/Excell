#pragma once
//�g�p�w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero:public CObj
{
public:
	CObjHero(int c);
	~CObjHero(){};

	void Init();
	void Action();
	void Draw();

private:
	float m_y; //��l���@ y�����ړ��p�ϐ�
	float m_x; //��l���@ x�����ړ��p�ϐ�
	
	bool  m_f_bu; //�e�۔��ː���p
	bool  m_f_bom; //�e�۔��ː���p

	float m_vx;//�������x�N�g���ϊ��p
	float m_vy;//�������x�N�g���ϊ��p

	int m_hp;
	int m_bullet;

	int m_o;
	int m_time;
	int de_time;
	int bar_time;
	int time;

	int Bullet_time;
	int Attack_Item;
	int Bar;
	int C;
};

