#pragma once
#include "car.h"
class Ambulance : public Car {
public:
	Ambulance();  //コンストラクタ
	~Ambulance(); //デストラクタ
	void sevePeople();
private:
	int m_number;
};