#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�G�@
class CObjitem :public CObj//�A�C�e��
{
public:
	CObjitem(float x, float y);
	~CObjitem() {};
	void Init(); //�C�j�V��
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_hp;
};
