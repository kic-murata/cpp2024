#pragma once
class Calc {
private:
	int m_a, m_b;
public:
	Calc();    //デフォルトコンストラクタ（引数なし）
	Calc(int a, int b);//コンストラクタ（引数あり）
	int add();            //足し算（引数なし）
	template <typename T>
	T add(T a, T b) {
		return a + b;
	}
	template <typename T,typename U>
	auto add(T a, U b) {
		return a + b;
	}
	int getA();
	int getB();
};