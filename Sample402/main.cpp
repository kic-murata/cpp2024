#include "car.h"
#include <iostream>
using namespace std;

int main() {
	{
	Car* pCar0 = nullptr;
	pCar0 = new Car();
		unique_ptr<Car> pCar = nullptr;
		pCar = make_unique<Car>();
		cout << "pCar0���̃A�h���X" << pCar0 << endl;
		cout << "pCar���̃A�h���X" << pCar << endl;
		//unique_ptr<Car> pCar(new Car());
		//pCar = new Car();
		cout << "����" << pCar->getSpeed() << "km/h" << endl;
		pCar->setSpeed(40);
		pCar->drive(1.5);
		pCar->setSpeed(60);
		pCar->drive(2.0);
		cout << "���s����" << pCar->getMigration() << "km" << endl;
		delete pCar0;
	}
	//delete pCar;
	cout << "�C���X�^���X�j��" << endl;
	return 0;
}