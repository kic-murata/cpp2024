#include "rat.h"
#include <iostream>
using namespace std;

int Rat::s_count = 0;//�ÓI�����o�ϐ��̏�����
Rat::Rat() :m_id(0) {
	m_id = ++s_count;
}
Rat::~Rat() {
	cout << "�l�Y�~:" << m_id << "����" << endl;
	s_count--;
}
void Rat::showNum() {
	cout << "�l�Y�~��" << s_count << "�C" << endl;
}
void Rat::squeak() {
	cout << m_id << ":�`���[�`���[" << endl;
}