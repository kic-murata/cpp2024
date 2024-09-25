#pragma once
#include "chara.h"

class Player : public Chara {
private:
	int m_Sp;
public:
	Player();
	Player(int, int, int, int);
	void setSp(int sp);
	int getSp();
};