#pragma once

#include "GameL/SceneObjManager.h"


using namespace GameL;

class CObjDes :public CObj
{
public:
	CObjDes() {};
	~CObjDes() {};
	void Init();  
	void Action();
	void Draw();  
private:
	bool m_key_flag;
};