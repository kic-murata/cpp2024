#include "car.h"
#include <iostream>
using namespace std;

void Car::setSpeed(double speed) {
	m_speed = speed;
}

void Car::drive(double hour) {
	cout << "����" << m_speed << "km��"
		<< hour << "���ԑ��s" << endl;
	cout << m_speed * hour 
		<< "km�ړ����܂����B" << endl;
}