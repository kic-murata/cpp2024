#include "chara.h"
#include "player.h"
#include <iostream>
using namespace std;

int main() {
	Player* pPlayer = new Player(100, 50, 20, 30);
	cout << "Player‚Ìó‘Ô HP:" << pPlayer->getHp()
		<< " SP:" << pPlayer->getSp()
		<< " Atk:" << pPlayer->getAtk()
		<< " Def:" << pPlayer->getDef() << endl;
	return 0;
}
