#pragma once
#include "chara.h"

class Player : public Chara {
private:
	int m_Sp;	//Sp（他のパラメータは親Charaクラスから継承）
public:
	Player();
	Player(string, int, int, int, int);
	void setSp(int sp);
	int getSp();
};