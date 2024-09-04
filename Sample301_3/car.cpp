#include "car.h"
#include <iostream>
using namespace std;

void Car::drive(double hour) {
	cout << "Žž‘¬" << speed << "km‚Å"
		<< hour << "ŽžŠÔ‘–s" << endl;
	cout << speed * hour <<
		"kmˆÚ“®‚µ‚Ü‚µ‚½B" << endl;
}