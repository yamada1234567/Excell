#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�{�X�@
class CObjBossima :public CObj
{
public:
	CObjBossima(float x, float y);//�R���X�g���N�^�ʒu�������炤
	~CObjBossima() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	float m_x;//�{�X�@��x�����̈ʒu
	float m_y;//�{�X�@��y�����̈ʒu
	int m_time;
};
