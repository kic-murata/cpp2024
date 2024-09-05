#include<iostream>
using namespace std;
int main()
{
	unique_ptr<int> p(new int());
	//int* p = nullptr;
	//p = new int();
	*p = 123;
	cout << *p << endl;
	//delete p;
	return 0;
}