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
	m_x = x;
	m_y = y; 

}

//�C�j�V�����C�Y
void CObjBoss::Init()
{
	m_hp = 50;
	m_time = 0;
	m_r = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHiyBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BOSS, 4);
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

	//�e�ۂƐڐG���Ă��邩�ǂ����𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
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
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;
	//�\���ʒu
	dst.m_top = 0.0f;
	dst.m_left = 32.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 32.0f;

	//1�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ec�̏������ɕ`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}