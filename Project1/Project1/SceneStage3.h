#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�V�[���F�Q�[�����C��
class CSceneStage3 :public CScene
{
public:
	CSceneStage3();
	~CSceneStage3();
	void InitScene();//�Q�[�����C���̏��������\�b�h
	void Scene();    //�Q�[�����C���̎��s�����\�b�h
private:
	int m_time;
};