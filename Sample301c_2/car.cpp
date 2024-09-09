#include "car.h"
#include <iostream>
using namespace std;

void Car::setSpeed(double speed) {
	m_speed = speed;
}

void Car::drive(double hour) {
	cout << "Žž‘¬" << m_speed << "km‚Å"
		<< hour << "ŽžŠÔ‘–s" << endl;
	cout << m_speed * hour 
		<< "kmˆÚ“®‚µ‚Ü‚µ‚½B" << endl;
}