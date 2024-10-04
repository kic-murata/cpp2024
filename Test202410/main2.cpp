#include <iostream>
using namespace std;
class Chara {
public:
	virtual void talk() {
		cout << "Hello" << endl;
	};
	void dead() {
		cout << "ゲームオーバー" << endl;
	}
};
class Player : public Chara {
public:
	void talk() {
		cout << "こんにちは" << endl;
	};
	void dead() {
		cout << "GAMEOVER" << endl;
	}
};
int main() {
	Player* pPlayer = new Player();
	pPlayer->talk();
	pPlayer->dead();
	delete pPlayer;
	return 0;
}