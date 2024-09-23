#pragma once
#include <iostream>
using namespace std;

class Chara {
protected:
	int m_Hp;
	int m_Atk;
	int m_Def;
public:
	Chara();
	Chara(int hp, int atk, int def);
	void setHp(int hp);
	int getHp();
	void setAtk(int atk);
	int getAtk();
	void setDef(int def);
	int getDef();
};