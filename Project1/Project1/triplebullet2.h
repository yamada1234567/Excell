#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjTripleBullet2 : public CObj
{
public:
	CObjTripleBullet2(float x, float y, float r, float speed); //�R���X�g���N�^
	~CObjTripleBullet2() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;//�ړ�����p�x
	float m_speed;//���x
};

