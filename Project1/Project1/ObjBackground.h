#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBackground : public CObj
{
public:
	CObjBackground() {}; //コンストラクタ
	~CObjBackground() {};
	void Init();
	void Action();
	void Draw();
private:
};
