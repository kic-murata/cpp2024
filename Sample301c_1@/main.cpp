#include "car.h"
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	std::vector<Car> vCar;
	vCar.push_back(Car());
	vCar.resize(3);
	cout << vCar.size() << endl;
	vCar[0].setSpeed(50);
	vCar[0].drive(1);
	vCar[2].setSpeed(40);
	vCar[2].drive(1.5);

	Car kuruma; //Carクラスからkurumaインスタンスを生成
	//kuruma.setSpeed(40);
	kuruma.drive(1.5);//kurumaのメンバ関数を実行
	return 0;
}