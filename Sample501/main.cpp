#include<iostream>
#include "car.h"
#include "ambulance.h"

using namespace std;

int main()
{
  cout << "Car�N���X�̏���" << endl;
  //Car* pkuruma = new Car();
  unique_ptr<Car> pkuruma(new Car());
  pkuruma->setSpeed(40);
  pkuruma->drive(1.5);
  cout << "���ړ�����:" << pkuruma->getMigration() << "km" << endl;
  //delete pkuruma;
  cout << "Ambulance�N���X�̏���" << endl;
  unique_ptr<Ambulance> pAmb(new Ambulance());
  //Ambulance* pAmb = new Ambulance();
  pAmb->setSpeed(60);
  pAmb->drive(2);
  cout << "���ړ�����:" << pAmb->getMigration() << "km" << endl;
  pAmb->savePeople();
  //delete pAmb;
  return 0;
}