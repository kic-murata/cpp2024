#include "rat.h"
#include <iostream>
using namespace std;
//Ratクラスの静的メンバ変数s_countを0に初期化
int Rat::s_count = 0;

Rat::Rat() : m_id(0) {
	s_count++;
	m_id = s_count;
	//cout << "ネズミ：" << m_id << " 生成" << endl;
}
Rat::~Rat() {
	cout << "ネズミ：" << m_id << " 消去" << endl;
	s_count--;
}
void Rat::showNum() {
	cout << "現在のネズミの数:" <<
		s_count << "匹です" << endl;
}
void Rat::squeak() {
	cout << m_id << ":チューチュー" << endl;
}