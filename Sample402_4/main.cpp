#include "car.h"
#include <iostream>
#include<memory>
int main()
{
	//Car* pKuruma = nullptr;
	//pKuruma = new Car();
	std::unique_ptr<Car> pKuruma(new Car());
	pKuruma->setSpeed(40);//kurumaのメンバ変数に値を代入
	pKuruma->drive(1.5);//kurumaのメンバ関数を実行
	pKuruma->drive(2.0);
	std::cout << "総移動距離:" <<
		pKuruma->getMigration() << "km" << std::endl;
	//delete pKuruma;
	std::cout << "インスタンス消去終了" << std::endl;
	return 0;
}