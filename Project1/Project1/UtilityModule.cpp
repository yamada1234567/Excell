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
		float r = atan2(h.w) * 180.0f / 3.14f;

		//-180���`-0����180���`360���ɕϊ�
	}