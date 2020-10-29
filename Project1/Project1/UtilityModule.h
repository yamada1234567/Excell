//プロトタイプ宣言
bool UniVec(float* vx, float* vy); //ベクトルの正規を行う関数

bool CheckWindow(float pos_x, float pos_y, float window_x, float windoow_y, float windoow_w, float windoow_h);//領域内かどうかチェックする関数

float GetAtan2Angle(float w, float h);//高さと幅で角度を求める

RECT_F GetBulletEffec(int* ani, int* ani_time, bool del, int timing);//delで弾丸のRECTや着弾effectのRECT(アニメーションのRECT)を返す
