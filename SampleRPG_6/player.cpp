#include "player.h"
//�����Ȃ��̃R���X�g���N�^
Player::Player() : Chara(NULL,0,0,0), m_Sp(0) {}
//�L�����N�^�̃p�����[�^�������Ƃ���R���X�g���N�^
Player::Player(string name, int hp, int atk, int def, int sp) :
	//Chara�N���X�̃R���X�g���N�^�ֈ�����n��
	Chara(name, hp, atk, def), m_Sp(sp) {}
//Sp�Z�b�^�[
void Player::setSp(int sp) {
	m_Sp = sp;
}
//Sp�Q�b�^�[
int Player::getSp() {
	return m_Sp;
}