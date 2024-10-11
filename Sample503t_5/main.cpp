#include <iostream>
#include "calc.h"
using namespace std;
int main() {
	Calc* pC1{}, * pC2{}; //Calcクラスのポインタ宣言
	pC1 = new Calc();			//引数なしのコンストラクタ
	pC2 = new Calc(1, 2);	//引数ありのコンストラクタ
	cout << 3 << "+" << 4 << "="
		<< pC1->add(3, 4) << endl;
	cout << pC2->getA() << "+" << pC2->getB()
		<< "=" << pC2->add() << endl;
	cout << 2.2 << "+" << 3.3 << "="
		<< pC1->add(2, 3.3) << endl;
	cout << "ABC" << "+" << "DEF" << "="
		<< pC1->add<string>("ABC", "DEF") << endl;
	delete pC1;
	delete pC2;
	return 0;
}