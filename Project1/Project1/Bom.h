#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBom : public CObj
{
public:
	CObjBom(float x, float y); //�R���X�g���N�^
	~CObjBom() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float si_x;
	float si_y;
	float m_vx;
	int m_time;
};
