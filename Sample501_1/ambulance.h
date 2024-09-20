#pragma once
#include "car.h"

class Ambulance: public Car {
public:
	Ambulance();  //コンストラクタ
	~Ambulance(); //デストラクタ
	void sevePeople();
	void drive(double hour);
private:
	int m_number;
};