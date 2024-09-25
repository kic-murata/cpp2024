#include "chara.h"
#include "player.h"
#include <iostream>
using namespace std;
int main() {
	Player* pPlayer = new Player(100, 50, 20, 30);
	cout << "Player‚Ìó‘Ô" << endl 
		<< " HP :" << pPlayer->getHp() <<endl
		<< " SP :" << pPlayer->getSp() << endl
		<< " Atk:" << pPlayer->getAtk() << endl
		<< " Def:" << pPlayer->getDef() << endl;
	delete pPlayer;
	return 0;
}
