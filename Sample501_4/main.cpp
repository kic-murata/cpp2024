#include "car.h"
#include "ambulance.h"
#include <iostream>

int main()
{
	Car kuruma; //Car�N���X����kuruma�C���X�^���X�𐶐�
	kuruma.setSpeed(40);//kuruma�̃����o�ϐ��ɒl����
	kuruma.drive(1.5);//kuruma�̃����o�֐������s
	kuruma.drive(2.0);
	std::cout << "���ړ�����:" <<
		kuruma.getMigration() << "km" << std::endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	std::cout << "���ړ�����:" <<
		pAmb->getMigration() << "km" << std::endl;
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}