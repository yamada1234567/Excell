#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ボス機
class CObjBoss6 :public CObj
{
public:
	CObjBoss6(float x, float y);//コンストラクタ位置情報をもらう
	~CObjBoss6() {};
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	float m_x;//ボス機のx方向の位置
	float m_y;//ボス機のy方向の位置
	float m_vx;//ボス機移動ベクトルX
	float m_vy;//ボス機移動ベクトル
	int m_hp;//ボスのヒットポイント
};