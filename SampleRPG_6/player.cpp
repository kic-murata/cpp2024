#include "player.h"
//引数なしのコンストラクタ
Player::Player() : Chara(NULL,0,0,0), m_Sp(0) {}
//キャラクタのパラメータを引数とするコンストラクタ
Player::Player(string name, int hp, int atk, int def, int sp) :
	//Charaクラスのコンストラクタへ引数を渡す
	Chara(name, hp, atk, def), m_Sp(sp) {}
//Spセッター
void Player::setSp(int sp) {
	m_Sp = sp;
}
//Spゲッター
int Player::getSp() {
	return m_Sp;
}