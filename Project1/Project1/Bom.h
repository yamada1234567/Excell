#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBom : public CObj
{
public:
	CObjBom(float x, float y); //コンストラクタ
	~CObjBom() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float si_x;
	float si_y;
	float m_vx;
	int m_time;
};
