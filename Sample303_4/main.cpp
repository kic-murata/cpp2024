#include "sample.h"

int main()
{
	Sample s;  //Sampleクラスのインスタンスs生成
	s.a = 1;   //メンバ変数aに1を代入
	//s.b = 2;   //メンバ変数bに2を代入
	s.func1(); //メンバ関数func1の実行
	//s.func2(); //メンバ関数func2の実行
	return 0;  //main関数の終了
}