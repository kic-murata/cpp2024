#include "car.h"
#include<iostream>
using namespace std;
int main()
{
	unique_ptr<Car> pkuruma(new Car());
	//Car* pkuruma = nullptr;
	//pkuruma = new Car();
	//Car kuruma; //Car�N���X����kuruma�C���X�^���X�𐶐�
	pkuruma->setSpeed(40);//kuruma�̃����o�ϐ��ɒl����
	pkuruma->drive(1.5);//kuruma�̃����o�֐������s
	pkuruma->setSpeed(60);//kuruma�̃����o�ϐ��ɒl����
	pkuruma->drive(2.0);//kuruma�̃����o�֐������s
	cout << "���ړ�����:" << pkuruma->getMigration()
		<< "km" << endl;
	//delete pkuruma;
	return 0;
}