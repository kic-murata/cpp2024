#include <iostream>
#include<stdio.h>
using namespace std;
void kansu(int a, int& b) {
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	a = 0;	//aはmain関数から渡された値のコピーを格納
	b = 1;	//bはmain関数から渡された変数（実体）の別名
}
int main() {
	int a = 100, b = 200;
	//printf("a:%d b:%d\n", a, b);
	kansu(a, b);
	cout << "a:" << a << endl
		<< "b:" << b << endl;
	return 0;
}
