#pragma once
//使用するヘッダー
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "meteoS.h"
//使用するネームスペース
using namespace GameL;
//イニシャライズ
void CObjmeteoS::Init()
{

}
//アクション
void CObjmeteoS::Action()
{

}
//ドロー
void CObjmeteoS::Draw()
{
	//描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	//切れ取り設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 50.0f;
	src.m_bottom = 50.0f;
	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 32.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 32.0f;
	//画像登録
	Draw::Draw(2, &src, &dst, c, 0.0f);
}