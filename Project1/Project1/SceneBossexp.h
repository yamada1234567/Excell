#pragma once
//�g�p����w�b�_�[
#include "GameL/SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���^�C�g��
class CSceneBossexp :public CScene
{
public:
	CSceneBossexp(int c);
	~CSceneBossexp();
	void InitScene();  //�Q�[���^�C�g���̏��������\�b�h
	void Scene();      //�Q�[���^�C�g���̎��s�����\�b�h
private:
	int Count;
	int m_time;
};

