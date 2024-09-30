#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//Player* pPlayer = new Player(100, 50, 20, 30);
	vector<Player*> pPlayer{ new Player(100, 50, 20, 30) };
	pPlayer.push_back(new Player(300, 70, 40, 50));
	//cout << "Player�̏�� HP:" << pPlayer->getHp()
	//	<< " SP:" << pPlayer->getSp()
	//	<< " Atk:" << pPlayer->getAtk()
	//	<< " Def:" << pPlayer->getDef() << endl;
	for (int i = 0; i < pPlayer.size(); i++) {
		cout << "adress:" << pPlayer[i] << endl;
		cout << "Player�̏��" << endl
			<< " HP: " << pPlayer.at(i)->getHp() << endl
			<< " SP: " << pPlayer[i]->getSp() << endl
			<< " Atk:" << pPlayer[i]->getAtk() << endl
			<< " Def:" << pPlayer[i]->getDef() << endl;
	}
	auto itr = pPlayer.begin();
	while ( itr != pPlayer.end() ) {
		cout << "�C���X�^���X�폜" << *itr << endl;
		delete *itr;
		//itr++;
		cout << "�z��폜" << endl;
		itr = pPlayer.erase(itr);
	}
	for (auto it : pPlayer) {
		cout << it << endl;
	}
	if (pPlayer.empty()) {
		cout << "empty!" << endl;
	}
	cout << endl << "size:" << pPlayer.size() << endl;
	return 0;
}
