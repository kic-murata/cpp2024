#include "car.h"
#include "ambulance.h"
#include<iostream>
using namespace std;
int main()
{
	cout << "Car�N���X�̏���" << endl;
	Car kuruma; //Car�N���X����kuruma�C���X�^���X�𐶐�
	kuruma.setSpeed(40);//kuruma�̃����o�ϐ��ɒl����
	kuruma.drive(1.5);//kuruma�̃����o�֐������s
	kuruma.setSpeed(60);//kuruma�̃����o�ϐ��ɒl����
	kuruma.drive(2.0);//kuruma�̃����o�֐������s
	cout << "���ړ�����:" << kuruma.getMigration()
		<< "km" << endl;
	cout << "Ambulance�N���X�̏���" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}