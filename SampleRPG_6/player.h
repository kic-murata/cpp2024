#pragma once
#include "chara.h"

class Player : public Chara {
private:
	int m_Sp;	//Sp�i���̃p�����[�^�͐eChara�N���X����p���j
public:
	Player();
	Player(string, int, int, int, int);
	void setSp(int sp);
	int getSp();
};