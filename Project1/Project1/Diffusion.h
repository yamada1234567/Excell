#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjDifBullet : public CObj
{
public:
	CObjDifBullet(float x, float y,float r,float spe); //�R���X�g���N�^
	~CObjDifBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;
	float m_speed;



};
