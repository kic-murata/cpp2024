#pragma once

class Calc {
private:
	int m_a, m_b;
public:
	Calc();    //デフォルトコンストラクタ（引数なし）
	Calc(int a, int b);//コンストラクタ（引数あり）
	int add();            //足し算処理（引数なし）
	int add(int a, int b);//足し算処理（引数あり）
	int getA();
	int getB();
};