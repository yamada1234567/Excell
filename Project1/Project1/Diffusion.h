#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjDifBullet : public CObj
{
public:
	CObjDifBullet(float x, float y,float r,float spe); //コンストラクタ
	~CObjDifBullet() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	float m_r;
	float m_speed;



};
