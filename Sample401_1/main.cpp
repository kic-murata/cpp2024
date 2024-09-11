#include "car.h"
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
	return 0;
}