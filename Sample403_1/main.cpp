#include<iostream>
using namespace std;
int main()
{
	int* p = nullptr;
	p = new int(123); //int a; p = &a;
	//*p = 123;
	cout << *p << endl;
	delete p;
	return 0;
}