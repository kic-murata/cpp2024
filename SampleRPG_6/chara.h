#pragma once
#include <iostream>
using namespace std;

class Chara {
protected:
	string m_Name;//ƒLƒƒƒ‰–¼
	int m_Hp;			//Hp
	int m_Atk;		//Atk
	int m_Def;		//Def
public:
	Chara();
	Chara(string name, int hp, int atk, int def);
	void setName(string name);
	string getName();
	void setHp(int hp);
	int getHp();
	void setAtk(int atk);
	int getAtk();
	void setDef(int def);
	int getDef();
};