#pragma once
//使用するヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:敵機
class CObjmeteoS :public CObj//メテオ小 
{
public:
	CObjmeteoS() {};
	~CObjmeteoS() {};
	void Init(); //イニシャ
	void Action();//アクション
	void Draw();//ドロー
private:
};