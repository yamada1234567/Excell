#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�{�X�@
class CObjBoss4 :public CObj
{
public:
	CObjBoss4(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjBoss4() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�{�X�@��x�����̈ʒu
	float m_y;//�{�X�@��y�����̈ʒu
	float m_vx;//�{�X�@�ړ��x�N�g��X
	float m_vy;//�{�X�@�ړ��x�N�g��
	int m_hp;//�{�X�̃q�b�g�|�C���g

	int de_time;
};