#include<math.h>
#include"GameL/DrawTexture.h"

using namespace GameL;

//---UnitVec�֐�
//�����P�@float*vx :�x�N�g����X�����̃|�C���^
//�����Q�@float*vy :�x�N�g����Y�����̃|�C���^
//�߂�l bool      :true=�v�Z�����@flase=�v�Z���s
//���e
//�����̃x�N�g���𐳓��������̒l��vx,vy�ɕύX���܂��B
bool UniVec(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);   //�������[�g�����߂�

	//�������O���ǂ������ׂ�
	if (r == 0.0f)
	{
		//�O�Ȃ牽�����Ȃ�
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r * (*vx);
		(*vy) = 1.0f / r * (*vy);
	}

	//�v�Z����
	return true;
}




//---CheckWindow�֐�
//����1 float pos_x:�̈�O���ǂ������ׂ�x�ʒu
//����2 float pos_y:�̈�O���ǂ������ׂ�y�ʒu
//����3 float windouw_x:�̈��top�ʒu
//����4 float windouw_y:�̈��left�ʒu
//����5 float windouw_w:�̈��right�ʒu
//����6 float windouw_h:�̈�� fase=�̈�O
//���e
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̓����O���𒲂ׂ�
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	//�̈�`�F�b�N
	if (pos_x < window_x)
	{
		return false;//�̈�O
	}
	if (pos_x > window_w)
	{
		return false;//�̈�O
	}
	if (pos_y < window_y)
	{
		return false;//�̈�O
	}
	if (pos_y > window_h)
	{
		return false;//�̈�O
	}

	return true;//�̈�O
}


	//---GetAtan2Angle�֐�
	//����1 float w:��
	//����2 float h:����
	//�߂�l float:�p�x(0���`360��)
	//���e
	//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�
	float GetAtan2Angle(float w, float h)
	{
		//atan2�Ŋp�x�����߂�
		float r = atan2(h,w) * 180.0f / 3.14f;

		//-180���`-0����180���`360���ɕϊ�
			//-180���`-0����180���`360���ɕϊ�
		if (r < 0)
		{
			r = 360 - fabs(r);
		}

		return r;
	}

	//--GetBulletEffec�֐�
//�����P�@int*  ani;�@�@ ���e�A�j���[�V����
//�����Q�@int*  ani_time;���e�A�j���[�V�����Ԋu�^�C��
//�����R�@bool  del;�@�@ �폜�`�F�b�N�itrue=���e�G�t�F�N�g�@false=�ʏ�̒e�ہj
//�����S  int   timing�@ �Ԋu���
//�߂�l  RECT_F eff;�@�@�`�悷��RECT
//del�Œe�ۂ�RECT�⒅�eeffect��(�A�j���[�V������RECT)��Ԃ�
	RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing)
	{
		//�Ԃ�RECT���
		RECT_F rect;

		//�t���O�Œʏ�e�ۂ����e�A�j���[�V������������
		if (del == true)
		{

			//���e�A�j���[�V����
			//���\�[�X���e�A�j���[�V�����ʒu
			RECT_F ani_src[4] =
			{
				{32,  0, 32, 64},
				{32, 32, 64, 64},
				{32, 64, 96, 64},
				{32, 96,128, 64},
			};
			//�A�j���[�V�����̃R�}�Ԋu
			if (*ani_time > timing)
			{
				*ani += 1;//�A�j���[�V�����̃R�}���P�i�߂�
				*ani_time = 0;
			}
			else
			{
				*ani_time += 1;
			}

			rect = ani_src[*ani];
		}
		else
		{
			//�e�ۂ̓A�j���[�V��������
			//���\�[�X�e�ۈʒu
			RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
			rect = bullet;

		}

		return rect;
	}