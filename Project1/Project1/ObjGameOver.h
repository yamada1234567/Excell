#pragma once

#include "GameL/SceneObjManager.h"


using namespace GameL;


class CObjGameOver :public CObj
{
public:
	CObjGameOver(int c);
	~CObjGameOver() {};
	void Init();  
	void Action();
	void Draw();  
private:
	bool m_key_flag;
	int SG;
};
