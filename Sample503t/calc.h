#pragma once
#include <string>
using namespace std;

class Calc {
private:
	int m_a, m_b;
public:
	Calc();    //�f�t�H���g�R���X�g���N�^�i�����Ȃ��j
	Calc(int a, int b);//�R���X�g���N�^�i��������j
	int add();            //�����Z�����i�����Ȃ��j
	template<typename T>
	T add(T a, T b);
	//inline T add(T a, T b)  {
	//	return a + b;
	//};
	//int add(int a, int b);//�����Z�����i��������j
	//double add(double a, double b);
	//string add(string a, string b);
	int getA();
	int getB();
};