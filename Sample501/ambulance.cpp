#include "ambulance.h"
#include <iostream>
using namespace std;

Ambulance::Ambulance() : m_number(119) {
	cout << "Ambulance�N���X�̃C���X�^���X����" << endl;
}
Ambulance::~Ambulance() {
	cout << "Ambulance�N���X�̃C���X�^���X����" << endl;
}
void Ambulance::savePeople() {
	cout << "�~�}�~������" << endl
		<< m_migration << endl
		<< "�Ăяo����" << m_number << "��" << endl;
}