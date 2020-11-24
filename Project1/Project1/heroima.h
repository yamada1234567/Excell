#pragma once
//使用ヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHeroime :public CObj
{
public:
	CObjHeroime();
	~CObjHeroime() {};

	void Init();
	void Action();
	void Draw();

private:


};


