#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���^�C�g��
class CSceneClear :public CScene
{
public:
	CSceneClear();
	~CSceneClear();
	void InitScene();  //�Q�[���^�C�g���̏��������\�b�h
	void Scene();      //�Q�[���^�C�g���̎��s�����\�b�h
private:
};
