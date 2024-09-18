#include "car.h"
#include "ambulance.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "-- CarNXฬ" << endl;
	Car kuruma;
	kuruma.setSpeed(40);
	kuruma.drive(1.5);
	kuruma.drive(2.0);
	cout << "ฺฎฃ:" <<
		kuruma.getMigration() << "km" << endl;
	cout << "-- AmbulanceNXฬ" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	cout << "ฺฎฃ:" <<
		pAmb->getMigration() << "km" << endl;
	pAmb->sevePeople();
	delete pAmb;
	return 0;
}