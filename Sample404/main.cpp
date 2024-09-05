#include<iostream>
using namespace std;
int main()
{
	unique_ptr<int[]> p(new int[10]);
	//int* p = nullptr;
	//p = new int[10];
	for (int i = 0; i < 10; i++) {
		p[i] = i;
		cout << p[i] << " ";
	}
	cout << endl;
	//delete[] p;
	return 0;
}