#include <iostream>
#include<stdio.h>
using namespace std;
void kansu(int a, int& b) {
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	a = 0;	//a��main�֐�����n���ꂽ�l�̃R�s�[���i�[
	b = 1;	//b��main�֐�����n���ꂽ�ϐ��i���́j�̕ʖ�
}
int main() {
	int a = 100, b = 200;
	//printf("a:%d b:%d\n", a, b);
	kansu(a, b);
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	return 0;
}
