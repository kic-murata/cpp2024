#include <iostream>
using namespace std;
int main()
{
	int* p = nullptr;
	p = new int[10];
	for (int i = 0; i < 10; i++) {
		p[i] = i; //*(p + i) = i;と同じ意味
		cout << p[i] << " ";
	}
	cout << endl;
	delete[] p;
	return 0;
}