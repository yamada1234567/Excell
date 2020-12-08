//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/DrawTexture.h"
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
			Scene::SetScene(new CSceneDes());
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
	//描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//切れ取り設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 780.0f;
	src.m_bottom = 600.0f;
	//表示位置
	dst.m_top = 0;
	dst.m_left = 0;
	dst.m_right = 800.0;
	dst.m_bottom = 600.0;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}