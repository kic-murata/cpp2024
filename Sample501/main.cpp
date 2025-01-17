#include<iostream>
#include "car.h"
#include "ambulance.h"

using namespace std;

int main()
{
  Car* m_car = new Car();
  cout << m_car << ":" << m_car->getMigration() << endl;
  cout << "CarNXฬ" << endl;
  Car* pkuruma0 = new Car();
  cout << pkuruma0 << ":" << pkuruma0->getMigration() << endl;
  unique_ptr<Car> pkuruma(new Car());
  cout << pkuruma << ":" << pkuruma->getMigration() << endl;
  pkuruma->setSpeed(40);
  pkuruma->drive(1.5);
  cout << "ฺฎฃ:" << pkuruma->getMigration() << "km" << endl;
  //delete pkuruma;
  cout << "AmbulanceNXฬ" << endl;
  unique_ptr<Ambulance> pAmb(new Ambulance());
  //Ambulance* pAmb = new Ambulance();
  pAmb->setSpeed(60);
  pAmb->drive(2);
  cout << "ฺฎฃ:" << pAmb->getMigration() << "km" << endl;
  pAmb->savePeople();
  //delete pAmb;
  return 0;
}