#include "rat.h"

int main() {
	Rat* r1, * r2, * r3;
	r1 = new Rat();//�C���X�^���Xr1����
	r1->squeak();
	Rat::showNum();
	r2 = new Rat();//�C���X�^���Xr2����
	r3 = new Rat();//�C���X�^���Xr3����
	r2->squeak();
	r3->squeak();
	Rat::showNum();
	delete r1;     //�C���X�^���Xr1����
	delete r2;     //�C���X�^���Xr2����
	Rat::showNum();
	delete r3;     //�C���X�^���Xr3����
	Rat::showNum();
	return 0;
}