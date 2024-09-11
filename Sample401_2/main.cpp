#include "car.h"
#include<iostream>
using namespace std;

int main()
{
	Car kuruma;
	kuruma.setSpeed(40);
	kuruma.drive(1.5);
	kuruma.drive(2.0);
	cout << "‘ˆÚ“®‹——£:" <<
		kuruma.getMigration() << "km" << endl;
	return 0;
}