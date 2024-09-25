#include "player.h"

Player::Player() : Chara(0,0,0), m_Sp(0) {}
Player::Player(int hp, int atk, int def, int sp) :
	Chara(hp, atk, def), m_Sp(sp) {}
void Player::setSp(int sp) {
	m_Sp = sp;
}
int Player::getSp() {
	return m_Sp;

}