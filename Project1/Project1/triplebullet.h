#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjTripleBullet : public CObj
{
public:
	CObjTripleBullet(float x, float y); //コンストラクタ
	~CObjTripleBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_speed;//速度
	

};
