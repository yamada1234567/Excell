#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�G�@
class CObjBomb :public CObj//�A�C�e��
{
public:
	CObjBomb(float x, float y);
	~CObjBomb() {};
	void Init(); //�C�j�V��
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
};