#include "calc.h"
#include <iostream>
using namespace std;
int main() {
	Calc* pC1{}, * pC2{};
	pC1 = new Calc();
	pC2 = new Calc(1, 2);
	cout << 3 << "+" << 4 << "=" << pC1->add<int>(3, 4) << endl;
	cout << pC2->getA() << "+" << pC2->getB()
		<< "=" << pC2->add() << endl;
	cout << 2.5 << "+" << 1.1 << "=" << pC1->add<double>(2.5, 1.1) << endl;
	cout << "ABC" << "+" << "DEF" << "=" << pC1->add<string>("ABC", "DEF") << endl;
	cout << 10 << "+" << 1.1 << "=" << pC1->add(10, 1.1) << endl;
	delete pC1;
	delete pC2;
}