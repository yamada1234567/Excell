#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ボス機
class CObjBossima :public CObj
{
public:
	CObjBossima(float x, float y);//コンストラクタ位置情報をもらう
	~CObjBossima() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//ボス機のx方向の位置
	float m_y;//ボス機のy方向の位置
	int m_time;
};
