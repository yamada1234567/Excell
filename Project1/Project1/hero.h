#pragma once
//使用ヘッダー
#include "GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero:public CObj
{
public:
	CObjHero(){};
	~CObjHero(){};

	void Init();
	void Action();
	void Draw();

private:
	float m_y;//主人公機 y方向移動用変数
	float m_x;//主人公機 x方向移動用変数
};

