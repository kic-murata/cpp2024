#include "calc.h"
//#include <string>


Calc::Calc() :m_a(0), m_b(0) {}
Calc::Calc(int a, int b) :m_a(a), m_b(b) {}
int Calc::add() {
	return m_a + m_b;
}
//template <typename T>
T Calc::add(T a, T b) {
	return a + b;
}
//int Calc::add(int a, int b) {
//	return a + b;
//}
//double Calc::add(double a, double b) {
//	return a + b;
//}
//string Calc::add(string a, string b) {
//	return a + b;
//}
int Calc::getA() {
	return m_a;
}
int Calc::getB() {
	return m_b;
}