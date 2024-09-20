#include "rat.h"
#include <iostream>
using namespace std;

int Rat::s_count = 0;//静的メンバ変数の初期化
Rat::Rat() :m_id(0) {
	m_id = ++s_count;
}
Rat::~Rat() {
	cout << "ネズミ:" << m_id << "消去" << endl;
	s_count--;
}
void Rat::showNum() {
	cout << "ネズミは" << s_count << "匹" << endl;
}
void Rat::squeak() {
	cout << m_id << ":チューチュー" << endl;
}