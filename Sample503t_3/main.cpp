#include <iostream>
#include "calc.h"
using namespace std;
int main()
{
	Calc* pC1{}, * pC2{};//pC1{} ‚Í pC1 = nullptr‚Æ“¯‹`
	pC1 = new Calc();
	pC2 = new Calc(1, 2);
	cout << 3 << "+" << 4 << "=" << pC1->add<int>(3, 4) << endl;
	cout << pC2->getA() << "+" << pC2->getB() << "="
		<< pC2->add() << endl;
	cout << 1.1 << "+" << 2.5 << "="
		<< pC1->add<double>(1.1, 2.5) << endl;
	cout << "ABC" << "+" << "DEF" << "="
		<< pC1->add<string>("ABC", "DEF") << endl;
	cout << 5 << "+" << 3.2 << "="
		<< pC1->add(5, 3.2) << endl;
	delete pC1;
	delete pC2;
	return 0;
}