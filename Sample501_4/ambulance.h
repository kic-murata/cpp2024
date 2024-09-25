#pragma once
#include "car.h"
class Ambulance : public Car {
public:
	Ambulance();  //コンストラクタ[クラス名+()]
	~Ambulance(); //デストラクタ[~クラス名+()]
	void sevePeople();
private:
	int m_number;
};