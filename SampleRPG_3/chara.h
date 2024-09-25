#pragma once
class Chara {
protected:
	int m_Hp;
	int m_Atk;
	int m_Def;
public:
	Chara();
	Chara(int hp, int atk, int def);
	int getHp();
	int getAtk();
	int getDef();
};