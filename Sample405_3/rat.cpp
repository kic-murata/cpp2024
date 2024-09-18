#include "rat.h"
#include <iostream>
using namespace std;

//静的メンバ変数s_countの初期化
//int Rat::s_count = 0;

Rat::Rat() : m_id(0) {
	s_count++;
	m_id = s_count;
}
Rat::~Rat() {
	cout << "ネズミ:" << m_id << "消去" << endl;
	s_count--;
}
void Rat::showNum() {
	cout << "現在のネズミの数は" << s_count << "匹" << endl;
}
void Rat::squeak() {
	cout << m_id << ":ちゅーちゅー" << endl;
}

