#pragma once
#include "car.h"
class Ambulance: public Car {
public:
	Ambulance();  //�R���X�g���N�^
	virtual ~Ambulance(); //�f�X�g���N�^
	void sevePeople();
	void drive(double a); //Car�N���X�̃I�[�o�[���C�h
private:
	int m_number;
};