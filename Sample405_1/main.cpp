#include "rat.h"

int main()
{
	Rat* r1, * r2, * r3; //Ratクラスのポインタ変数宣言
	r1 = new Rat(); //ネズミ1のインスタンス生成
	r1->squeak();   //ネズミ1が鳴く
	Rat::showNum(); //ネズミの総数の表示
	r2 = new Rat(); //ネズミ2のインスタンス生成
	r3 = new Rat(); //ネズミ3　　　　〃
	r2->squeak();   //ネズミ2が鳴く
	r3->squeak();   //ネズミ3が 〃
	Rat::showNum(); //ネズミの総数の表示
	delete r1;      //ネズミ1のインスタンス消去
	delete r2;      //ネズミ2の　　　〃
	Rat::showNum(); //ネズミの総数の表示
	delete r3;      //ネズミ3のインスタンス消去
	Rat::showNum(); //ネズミの総数の表示
	return 0;
}