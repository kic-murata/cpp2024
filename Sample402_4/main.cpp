#include "car.h"
#include <iostream>
#include<memory>
int main()
{
	//Car* pKuruma = nullptr;
	//pKuruma = new Car();
	std::unique_ptr<Car> pKuruma(new Car());
	pKuruma->setSpeed(40);//kuruma�̃����o�ϐ��ɒl����
	pKuruma->drive(1.5);//kuruma�̃����o�֐������s
	pKuruma->drive(2.0);
	std::cout << "���ړ�����:" <<
		pKuruma->getMigration() << "km" << std::endl;
	//delete pKuruma;
	std::cout << "�C���X�^���X�����I��" << std::endl;
	return 0;
}