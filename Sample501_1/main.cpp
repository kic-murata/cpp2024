#include "car.h"
#include "ambulance.h"
#include <iostream>
using namespace std;

int main()
{
	Car kuruma; //Car�N���X����kuruma�C���X�^���X�𐶐�
	kuruma.setSpeed(40);
	kuruma.drive(1.5);//kuruma�̃����o�֐������s
	kuruma.drive(2.0);
	cout << "���ړ�����:" << kuruma.getMigration()
		<< "km" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	cout << "���ړ�����:" << pAmb->getMigration()
		<< "km" << endl;
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}