#pragma once
#include <string>
using namespace std;

class Calc {
private:
	int m_a, m_b;
public:
	Calc();    //デフォルトコンストラクタ（引数なし）
	Calc(int a, int b);//コンストラクタ（引数あり）
	int add();            //足し算処理（引数なし）
	template<typename T>
	T add(T a, T b);
	//inline T add(T a, T b)  {
	//	return a + b;
	//};
	//int add(int a, int b);//足し算処理（引数あり）
	//double add(double a, double b);
	//string add(string a, string b);
	int getA();
	int getB();
};