#include "car.h"
#include<iostream>
using namespace std;
int main()
{
	unique_ptr<Car> pkuruma(new Car());
	//Car* pkuruma = nullptr;
	//pkuruma = new Car();
	//Car kuruma; //Carクラスからkurumaインスタンスを生成
	pkuruma->setSpeed(40);//kurumaのメンバ変数に値を代入
	pkuruma->drive(1.5);//kurumaのメンバ関数を実行
	pkuruma->setSpeed(60);//kurumaのメンバ変数に値を代入
	pkuruma->drive(2.0);//kurumaのメンバ関数を実行
	cout << "総移動距離:" << pkuruma->getMigration()
		<< "km" << endl;
	//delete pkuruma;
	return 0;
}