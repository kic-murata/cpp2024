#include <iostream>
using namespace std;
class Chara {
public:
	virtual void talk() {
		cout << "Hello" << endl;
	};
	void dead() {
		cout << "�Q�[���I�[�o�[" << endl;
	}
};
class Player : public Chara {
public:
	void talk() {
		cout << "����ɂ���" << endl;
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