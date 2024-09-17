#include "car.h"
#include "ambulance.h"
#include <iostream>
using namespace std;

int main()
{
	Car kuruma; //Carクラスからkurumaインスタンスを生成
	kuruma.setSpeed(40);
	kuruma.drive(1.5);//kurumaのメンバ関数を実行
	kuruma.drive(2.0);
	cout << "総移動距離:" << kuruma.getMigration()
		<< "km" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	cout << "総移動距離:" << pAmb->getMigration()
		<< "km" << endl;
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}