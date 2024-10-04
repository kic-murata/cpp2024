#include "car.h"
#include "ambulance.h"
#include<iostream>
using namespace std;
int main()
{
	cout << "Carクラスの処理" << endl;
	Car kuruma; //Carクラスからkurumaインスタンスを生成
	kuruma.setSpeed(40);//kurumaのメンバ変数に値を代入
	kuruma.drive(1.5);//kurumaのメンバ関数を実行
	kuruma.setSpeed(60);//kurumaのメンバ変数に値を代入
	kuruma.drive(2.0);//kurumaのメンバ関数を実行
	cout << "総移動距離:" << kuruma.getMigration()
		<< "km" << endl;
	cout << "Ambulanceクラスの処理" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}