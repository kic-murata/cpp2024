#pragma once
#include <string>
using namespace std;
class Calc {
private:
	int m_a, m_b;
public:
	Calc();
	Calc(int a, int b);
	int add();
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