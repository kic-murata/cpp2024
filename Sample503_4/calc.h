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
	int add(int a, int b);
	double add(double a, double b);
	string add(string a, string b);
	int getA();
	int getB();
};