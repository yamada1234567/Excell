//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "BomBullet.h"
#include "GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBomBullet::CObjBomBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBomBullet::Init()
{
	m_vx = 0.0f;

	//�����蔻��쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_BULLET, OBJ_BOM_BULLET, 1);
}

//�A�N�V����
void CObjBomBullet::Action()
{
	m_y += -12.0f;

	m_x += m_vx;

	//�̈�O�ɏo����폜
	if (m_x < 0.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//hitbox�X�V�p�|�C���^�[�̎擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);



	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG������폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		CObjBom* obj_b = new CObjBom(m_x, m_y);
		Objs::InsertObj(obj_b, OBJ_BOM, 1);
	}
}

//�h���[
void CObjBomBullet::Draw()
{
	//�`�ʃJ���[��� R=RED G=Green B=Blue A=alpha
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	//1�Ԃɓo�^�����O���t�B�b�N���̏������Ƃɕ`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}