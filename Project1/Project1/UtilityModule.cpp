//---CheckWindow関数
//引数1 float pos_x:領域外かどうか調べるx位置
//引数2 float pos_y:領域外かどうか調べるy位置
//引数3 float windouw_x:領域のtop位置
//引数4 float windouw_y:領域のleft位置
//引数5 float windouw_w:領域のright位置
//引数6 float windouw_h:領域内 fase=領域外
//内容
//領域内かどうか調べる位置pos_(x,y)がwindow_(xywh)の内か外かを調べる
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	//領域チェック
	if (pos_x < window_x)
	{
		return false;//領域外
	}
	if (pos_x > window_w)
	{
		return false;//領域外
	}
	if (pos_y < window_y)
	{
		return false;//領域外
	}
	if (pos_y > window_h)
	{
		return false;//領域外
	}

	return true;//領域外
}


	//---GetAtan2Angle関数
	//引数1 float w:幅
	//引数2 float h:高さ
	//戻り値 float:角度(0°～360°)
	//内容
	//高さと幅から直角三角形があると仮定しその角度を求める
	float GetAtan2Angle(float w, float h)
	{
		//atan2で角度を求める
		float r = atan2(h.w) * 180.0f / 3.14f;

		//-180°～-0°を180°～360°に変換
	}