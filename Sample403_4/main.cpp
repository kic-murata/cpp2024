#include<iostream>

int main()
{
	int* p = nullptr;
	p = new int();
	*p = 123;
	std::cout << *p << std::endl;
	delete p;
	return 0;
}