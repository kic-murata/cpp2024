#include "chara.h"
#include "player.h"
#include <iostream>
using namespace std;

int main() {
	Player* pPlayer = new Player(100, 50, 20, 30);
	HpClass* pHp1 = new Player::pHp();
	cout << "pPlayer�̃A�h���X:" << pPlayer->pHp << endl;
	//pPlayer->pHp->setHp(200);
	cout << "Player�̏�� HP:" << pPlayer->pHp->getHp();
		;		/*	<< " SP:" << pPlayer->getSp()
		<< " Atk:" << pPlayer->getAtk()
		<< " Def:" << pPlayer->getDef() << endl;*/
	return 0;
}
