#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�G�@
class CObjmeteoLD :public CObj//���e�I�����ɐi��
{
public:
	CObjmeteoLD(float x, float y);
	~CObjmeteoLD() {};
	void Init(); //�C�j�V��
	void Action();//�A�N�V����
	void Draw();//�h���[
	void SetVector(float vx, float vy);
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_left_bottom;
	float m_top_right;


	int m_hp;
	int m_time;

};