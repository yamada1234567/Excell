#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームタイトル
class CObjClear :public CObj
{
public:
	CObjClear(int Cou);
	~CObjClear() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
private:
	bool m_key_flag;//キーフラグ
	int SG;
};
