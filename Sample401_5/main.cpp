#include "car.h"
#include<iostream>
using namespace std;
int main()
{
	Car kuruma; //Car�N���X����kuruma�C���X�^���X�𐶐�
	//kuruma.setSpeed(40);//kuruma�̃����o�ϐ��ɒl����
	kuruma.drive(1.5);//kuruma�̃����o�֐������s
	kuruma.setSpeed(60);//kuruma�̃����o�ϐ��ɒl����
	kuruma.drive(2.0);//kuruma�̃����o�֐������s
	cout << "���ړ�����:" << kuruma.getMigration()
		<< "km" << endl;
	return 0;
}