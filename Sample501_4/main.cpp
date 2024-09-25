#include "car.h"
#include "ambulance.h"
#include <iostream>

int main()
{
	Car kuruma; //Carクラスからkurumaインスタンスを生成
	kuruma.setSpeed(40);//kurumaのメンバ変数に値を代入
	kuruma.drive(1.5);//kurumaのメンバ関数を実行
	kuruma.drive(2.0);
	std::cout << "総移動距離:" <<
		kuruma.getMigration() << "km" << std::endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	std::cout << "総移動距離:" <<
		pAmb->getMigration() << "km" << std::endl;
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}