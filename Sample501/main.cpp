#include<iostream>
#include "car.h"
#include "ambulance.h"

using namespace std;

int main()
{
  Car* m_car = new Car();
  cout << m_car << ":" << m_car->getMigration() << endl;
  cout << "Carクラスの処理" << endl;
  Car* pkuruma0 = new Car();
  cout << pkuruma0 << ":" << pkuruma0->getMigration() << endl;
  unique_ptr<Car> pkuruma(new Car());
  cout << pkuruma << ":" << pkuruma->getMigration() << endl;
  pkuruma->setSpeed(40);
  pkuruma->drive(1.5);
  cout << "総移動距離:" << pkuruma->getMigration() << "km" << endl;
  //delete pkuruma;
  cout << "Ambulanceクラスの処理" << endl;
  unique_ptr<Ambulance> pAmb(new Ambulance());
  //Ambulance* pAmb = new Ambulance();
  pAmb->setSpeed(60);
  pAmb->drive(2);
  cout << "総移動距離:" << pAmb->getMigration() << "km" << endl;
  pAmb->savePeople();
  //delete pAmb;
  return 0;
}