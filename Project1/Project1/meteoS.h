#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�G�@
class CObjmeteoS :public CObj//���e�I�� 
{
public:
	CObjmeteoS(float x,float y);
	~CObjmeteoS() {};
	void Init(); //�C�j�V��
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x; 
	float m_y;
	float m_vx;
	float m_vy;
	//int m_health;
};