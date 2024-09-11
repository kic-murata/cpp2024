#include "car.h"
#include <iostream>
using namespace std;

Car::Car() : m_speed(60.0), m_migration(0.0) {
	cout << "Carクラスのインスタンス生成" << endl;
}
Car::~Car() {
	cout << "Carクラスのインスタンス消去" << endl;
}
double Car::getMigration() {
	return m_migration;
}
void Car::setSpeed(double speed) {
	m_speed = speed;
}
void Car::drive(double hour) {
	cout << "時速" << m_speed << "kmで" <<
		hour << "時間走行" << endl;
	cout << m_speed * hour <<
		"km移動しました" << endl;
	m_migration += m_speed * hour;
}