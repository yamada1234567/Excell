//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	//m_key_flag = false;//�L�[�t���O
}

//�A�N�V����
void CObjGameOver::Action()
{

}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"YOU LOST", 325, 200, 32, c);
	Font::StrDraw(L"GAME OVER", 320, 250, 32, c);
	Font::StrDraw(L"NEXT_CHALLENGE:ENTER_KEY", 200, 350, 32, c);

}