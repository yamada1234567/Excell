//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"Boss.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBoss::CObjBoss(float x, float y)
{

	//�\���ʒu
	m_x = x+100;
	m_y = y-150; 

}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_hp = 20;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHiyBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 420, 420, ELEMENT_ENEMY, OBJ_BOSS, 6);
}
//�A�N�V����
void CObjBoss::Action()
{
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	////�{�X�@�����S�ɗ̈�O�ɏo����{�X�@��j������
	//bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 600.0f);
	//if (check == false)
	//{
	//	this->SetStatus(false);//���g�ɍ폜���߂��o��
	//	Hits::DeleteHitBox(this);//�{�X�@�����L����HitBox�ɍ폜����
	//}

	//�_���[�W����
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		m_hp -= 1;
		if (0 >= m_hp)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			//�N���A�Ɉړ�
			Scene::SetScene(new CSceneClear(0));
			
		}

	}
}
//�h���[
void CObjBoss::Draw()
{
	//�`��J���[��� R=RED G=Green B=Blue A=alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 530.0f;
	src.m_bottom = 530.0f;
	//�\���ʒu
	dst.m_top = 0.0f+m_y;
	dst.m_left = 420.0f+m_x;
	dst.m_right = 0.0f+m_x;
	dst.m_bottom = 420.0f+ m_y;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(6, &src, &dst, c, 0.0f);
}