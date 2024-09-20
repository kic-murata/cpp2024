#pragma once
#include "car.h"
class Ambulance: public Car {
public:
	Ambulance();  //コンストラクタ
	virtual ~Ambulance(); //デストラクタ
	void sevePeople();
	void drive(double a); //Carクラスのオーバーライド
private:
	int m_number;
};