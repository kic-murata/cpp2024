#include "car.h"
#include <iostream>
using namespace std;

int main()
{
	Car* pkuruma = nullptr;
	pkuruma = new Car();
	pkuruma->setSpeed(40);
	pkuruma->drive(1.5);//kurumaのメンバ関数を実行
	pkuruma->drive(2.0);
	cout << "総移動距離:" << pkuruma->getMigration()
		<< "km" << endl;
	return 0;
}