#include "rat.h"

int main() {
	Rat* r1, * r2, * r3;
	r1 = new Rat();//インスタンスr1生成
	r1->squeak();
	Rat::showNum();
	r2 = new Rat();//インスタンスr2生成
	r3 = new Rat();//インスタンスr3生成
	r2->squeak();
	r3->squeak();
	Rat::showNum();
	delete r1;     //インスタンスr1消去
	delete r2;     //インスタンスr2消去
	Rat::showNum();
	delete r3;     //インスタンスr3消去
	Rat::showNum();
	return 0;
}