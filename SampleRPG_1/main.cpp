#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<Player*> pPlayer{ new Player(100, 50, 20, 30) };
	pPlayer.push_back(new Player(300, 70, 40, 50));
	for (int i = 0; i < pPlayer.size(); i++) {
		cout << "Playerの状態" << endl
			<< " HP :" << pPlayer[i]->getHp() << endl
			<< " SP :" << pPlayer[i]->getSp() << endl
			<< " Atk:" << pPlayer[i]->getAtk() << endl
			<< " Def:" << pPlayer[i]->getDef() << endl;
	}
	auto itr = pPlayer.begin(); //先頭要素のイテレータを取得
	while(itr != pPlayer.end()){//末尾の要素までループ
		delete* itr;              //インスタンスのメモリを解放
		itr = pPlayer.erase(itr);//要素を削除してイテレータ更新
	}
	cout << "pPlayerの要素数:" << pPlayer.size() << endl;
	return 0;
}
