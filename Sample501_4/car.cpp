#include "car.h"
#include <iostream>
using namespace std;

Car::Car() : m_speed(60.0), m_migration(0.0) {
	cout << "Car�N���X�̃C���X�^���X����" << endl;
}
Car::~Car() {
	cout << "Car�N���X�̃C���X�^���X����" << endl;
}
double Car::getMigration() {
	return m_migration;
}
void Car::setSpeed(double speed) {
	m_speed = speed;
}
void Car::drive(double hour) {
	cout << "����" << m_speed << "km��" <<
		hour << "���ԑ��s" << endl;
	cout << m_speed * hour <<
		"km�ړ����܂���" << endl;
	m_migration += m_speed * hour;
}