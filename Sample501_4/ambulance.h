#pragma once
#include "car.h"
class Ambulance : public Car {
public:
	Ambulance();  //�R���X�g���N�^[�N���X��+()]
	~Ambulance(); //�f�X�g���N�^[~�N���X��+()]
	void sevePeople();
private:
	int m_number;
};