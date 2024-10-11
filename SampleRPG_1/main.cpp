#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<Player*> pPlayer{ new Player(100, 50, 20, 30) };
	pPlayer.push_back(new Player(300, 70, 40, 50));
	for (int i = 0; i < pPlayer.size(); i++) {
		cout << "Player�̏��" << endl
			<< " HP :" << pPlayer[i]->getHp() << endl
			<< " SP :" << pPlayer[i]->getSp() << endl
			<< " Atk:" << pPlayer[i]->getAtk() << endl
			<< " Def:" << pPlayer[i]->getDef() << endl;
	}
	auto itr = pPlayer.begin(); //�擪�v�f�̃C�e���[�^���擾
	while(itr != pPlayer.end()){//�����̗v�f�܂Ń��[�v
		delete* itr;              //�C���X�^���X�̃����������
		itr = pPlayer.erase(itr);//�v�f���폜���ăC�e���[�^�X�V
	}
	cout << "pPlayer�̗v�f��:" << pPlayer.size() << endl;
	return 0;
}
