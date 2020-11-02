#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjTripleBullet2 : public CObj
{
public:
	CObjTripleBullet2(float x, float y, float r, float speed); //コンストラクタ
	~CObjTripleBullet2() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;//移動する角度
	float m_speed;//速度
};

