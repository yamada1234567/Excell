//使用するヘッダーファイル
#include "GameL/DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjClear::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjClear::Action()
{
	//エンターキーを押してシーン：ゲームメインに移動する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneStage2());
		m_key_flag = true;
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"1ステージクリア！", 260, 225, 32, c);
	Font::StrDraw(L"next:ENTER_KEY", 225, 275, 50, c);
						        //y座標(左右) , x座標(上下) , サイズ
}