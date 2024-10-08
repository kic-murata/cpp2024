#pragma once
#include "car.h"

class Ambulance : public Car {
public:
	Ambulance();  //コンストラクタ
	~Ambulance(); //デストラクタ
//	virtual ~Ambulance(); //デストラクタ
	void savePeople();
private:
	int m_number;
};