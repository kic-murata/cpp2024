#include "chara.h"

//�����Ȃ��̃R���X�g���N�^
Chara::Chara() : m_Name(NULL), m_Hp(0), m_Atk(0), m_Def(0) {}
//�L�����N�^�̃p�����[�^�������Ƃ���R���X�g���N�^�iPlayer�N���X����Ăяo�����j
Chara::Chara(string name, int hp, int atk, int def)
	: m_Name(name), m_Hp(hp), m_Atk(atk), m_Def(def) {}
//Name�Z�b�^�[
void Chara::setName(string name) {
	m_Name = name;
}
//Hp�Z�b�^�[
void Chara::setHp(int hp) {
	m_Hp = hp;
}
//Atk�Z�b�^�[
void Chara::setAtk(int atk) {
	m_Atk = atk;
}
//Def�Z�b�^�[
void Chara::setDef(int def) {
	m_Def = def;
}
//Name�Q�b�^�[
string Chara::getName() {
	return m_Name;
}
//Hp�Q�b�^�[
int Chara::getHp() {
	return m_Hp;
}
//Atk�Q�b�^�[
int Chara::getAtk() {
	return m_Atk;
}
//Def�Q�b�^�[
int Chara::getDef() {
	return m_Def;
}