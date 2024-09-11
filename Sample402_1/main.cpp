#include "car.h"
#include <iostream>
using namespace std;

int main()
{
	Car* pkuruma = nullptr;
	pkuruma = new Car();
	pkuruma->setSpeed(40);
	pkuruma->drive(1.5);//kuruma‚Ìƒƒ“ƒoŠÖ”‚ðŽÀs
	pkuruma->drive(2.0);
	cout << "‘ˆÚ“®‹——£:" << pkuruma->getMigration()
		<< "km" << endl;
	return 0;
}