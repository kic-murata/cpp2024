#include "chara.h"

Chara::Chara() :  m_Atk(0), m_Def(0) {
	init();
}
Chara::Chara(int hp, int atk, int def)
	:  m_Atk(atk), m_Def(def) {
	init();
}
void Chara::init() {
	HpClass* pHp = new HpClass();
}

//void Chara::setHp(int hp) {
//	m_Hp = hp;
//}
void Chara::setAtk(int atk) {
	m_Atk = atk;
}
void Chara::setDef(int def) {
	m_Def = def;
}
//int Chara::getHp() {
//	return m_Hp;
//}
int Chara::getAtk() {
	return m_Atk;
}
int Chara::getDef() {
	return m_Def;
}