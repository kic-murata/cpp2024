#include "rat.h"

int main()
{
	Rat* r1, * r2, * r3;
	r1 = new Rat(); //１匹目のネズミインスタンスを生成
	r1->squeak();   //ネズミ１が鳴く
	Rat::showNum(); //ネズミの総数を表示（静的メンバ関数の実行）
	r2 = new Rat(); //ネズミ2のインスタンスを生成
	r3 = new Rat(); //ネズミ3のインスタンスを生成
	r2->squeak();   //ネズミ2が鳴く
	r3->squeak();   //ネズミ3が鳴く
	Rat::showNum(); //ネズミの総数を表示
	delete r1;      //ネズミ1のインスタンスを消去
	delete r2;      //ネズミ2のインスタンスを消去
	Rat::showNum(); //ネズミの総数を表示
	delete r3;      //ネズミ3のインスタンスを消去
	Rat::showNum(); //ネズミの総数を表示
	return 0;
}