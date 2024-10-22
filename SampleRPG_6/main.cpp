#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>
using namespace std;

//vectorコンテナの要素に、Playerクラスのインスタンスのアドレスを
//格納して、パラメータを表示するプログラム。
//表示後は、インスタンスの消去と要素の削除を行う。
int main() {
	//                                  Name   Hp   Atk Def Sp
	vector<Player*> pPlayer{ new Player("勇者", 200, 80, 20, 80) };
	pPlayer.push_back(new Player("戦士", 300, 90, 40, 10));
	pPlayer.push_back(new Player("魔法使い", 80, 10, 20, 200));
	pPlayer.push_back(new Player("僧侶", 180, 60, 60, 120));
	cout << "生成したキャラクタ数:" << pPlayer.size() << endl;
	for (int i = 0; i < pPlayer.size(); i++) {
		cout 
			<< " Name:" << pPlayer[i]->getName() << endl
			<< "   HP:" << pPlayer[i]->getHp() << endl
			<< "   SP:" << pPlayer[i]->getSp() << endl
			<< "  Atk:" << pPlayer[i]->getAtk() << endl
			<< "  Def:" << pPlayer[i]->getDef() << endl;
	}
	auto itr = pPlayer.begin();	//vectorの先頭要素のイテレータ取得
	while ( itr != pPlayer.end() ) {
		cout << (*itr)->getName() << "のインスタンス削除" << " > ";
		delete *itr;	//インスタンスが使用していたアドレス領域を解放
		cout << "配列の要素を削除" << endl;
		itr = pPlayer.erase(itr);	//vectorの要素を削除
		if (pPlayer.empty()) {	//vectorの要素が空になったかをチェック
			cout << "すべてのインスタンスを消去完了" << endl;
		}
	}
	return 0;
}
