#include "sample.h"
#include <iostream>
using namespace std;
int main()
{
	Sample s;
	s.setNum(5);
	cout << "m_num:" << s.getNum() << endl;
	return 0;
}