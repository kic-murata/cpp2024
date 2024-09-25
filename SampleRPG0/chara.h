#pragma once
#include <iostream>
using namespace std;

class HpClass;

class Chara {
private:
	void init();
protected:
//	int m_Hp;
	int m_Atk;
	int m_Def;
public:
	HpClass* pHp;
	Chara();
	Chara(int hp, int atk, int def);
	~Chara();
	//void setHp(int hp);
	//int getHp();
	void setAtk(int atk);
	int getAtk();
	void setDef(int def);
	int getDef();
};

class HpClass {
protected:
	int m_Hp;
public:
	int getHp() {
		return m_Hp;
	}
	void setHp(int hp) {
		m_Hp = hp;
	}
};