//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"

#include "GameHead.h"
#include "ObjTitle.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン：ゲームメインに移動する
	if (Input::GetVKey(VK_RETURN)==true)
	{
		if (m_key_flag==true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"メテオブレイカー", 150, 200, 64, c);

	Font::StrDraw(L"Enter:スタート", 260, 350, 32, c);
								//y座標(左右) , x座標(上下) , サイズ
}