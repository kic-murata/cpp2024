#include "car.h"
#include<iostream>
using namespace std;

int main()
{
	//Car* pKuruma = nullptr;
	//pKuruma = new Car();
	unique_ptr<Car> pKuruma(new Car());
	pKuruma->setSpeed(40);
	pKuruma->drive(1.5);
	pKuruma->drive(2.0);
	cout << "総移動距離:" <<
		pKuruma->getMigration() << "km" << endl;
	//delete pKuruma;
	cout << "インスタンス消去終了" << endl;
	return 0;
}