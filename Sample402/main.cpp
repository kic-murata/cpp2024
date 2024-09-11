#include "car.h"
#include <iostream>
using namespace std;

int main() {
	{
	Car* pCar0 = nullptr;
	pCar0 = new Car();
		unique_ptr<Car> pCar = nullptr;
		pCar = make_unique<Car>();
		cout << "pCar0内のアドレス" << pCar0 << endl;
		cout << "pCar内のアドレス" << pCar << endl;
		//unique_ptr<Car> pCar(new Car());
		//pCar = new Car();
		cout << "時速" << pCar->getSpeed() << "km/h" << endl;
		pCar->setSpeed(40);
		pCar->drive(1.5);
		pCar->setSpeed(60);
		pCar->drive(2.0);
		cout << "走行距離" << pCar->getMigration() << "km" << endl;
		delete pCar0;
	}
	//delete pCar;
	cout << "インスタンス破棄" << endl;
	return 0;
}