#include "car.h"
#include <iostream>
using namespace std;

int main()
{
	unique_ptr<Car> pkuruma(new Car());
	//Car* pkuruma = nullptr;
	//pkuruma = new Car();
	pkuruma->setSpeed(40);
	pkuruma->drive(1.5);//kuruma�̃����o�֐������s
	pkuruma->drive(2.0);
	cout << "���ړ�����:" << pkuruma->getMigration()
		<< "km" << endl;
	//delete pkuruma;
	return 0;
}