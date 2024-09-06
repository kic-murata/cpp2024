#include "sample.h"
#include <iostream>
using namespace std;

void Sample::func1() {
	cout << "func1" << endl;
	a = 1;
	b = 2;
	func2();
}
void Sample::func2() {
	cout << "func2" << endl;
	a = 2;
	b = 2;
	cout << "a=" << a << ",b=" << b << endl;
}