#include "chara.h"

//引数なしのコンストラクタ
Chara::Chara() : m_Name(NULL), m_Hp(0), m_Atk(0), m_Def(0) {}
//キャラクタのパラメータを引数とするコンストラクタ（Playerクラスから呼び出される）
Chara::Chara(string name, int hp, int atk, int def)
	: m_Name(name), m_Hp(hp), m_Atk(atk), m_Def(def) {}
//Nameセッター
void Chara::setName(string name) {
	m_Name = name;
}
//Hpセッター
void Chara::setHp(int hp) {
	m_Hp = hp;
}
//Atkセッター
void Chara::setAtk(int atk) {
	m_Atk = atk;
}
//Defセッター
void Chara::setDef(int def) {
	m_Def = def;
}
//Nameゲッター
string Chara::getName() {
	return m_Name;
}
//Hpゲッター
int Chara::getHp() {
	return m_Hp;
}
//Atkゲッター
int Chara::getAtk() {
	return m_Atk;
}
//Defゲッター
int Chara::getDef() {
	return m_Def;
}