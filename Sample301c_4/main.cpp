#include "car.h"

int main()
{
	Car kuruma; //Carクラスからkurumaインスタンスを生成
	//kuruma.setSpeed(140);//kurumaのメンバ変数に値を代入
	kuruma.drive(1.5);//kurumaのメンバ関数を実行
	return 0;
}