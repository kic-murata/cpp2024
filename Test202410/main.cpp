#pragma once
#include <iostream>
class Hp {
public:
	void setHp(int hp) {
		m_hp = hp;
	}
private:
	int m_hp;
};
int main() {
	Hp* pHp = new Hp();
	std::cout << "SetHp" << 100;
	pHp->setHp(100);
	return 0;
}