#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBackground : public CObj
{
public:
	CObjBackground() {}; //�R���X�g���N�^
	~CObjBackground() {};
	void Init();
	void Action();
	void Draw();
private:
};
