#pragma once

class Car {
public:
	Car();  //�R���X�g���N�^
	virtual ~Car(); //�f�X�g���N�^
	double getMigration();
	void setSpeed(double speed);
	void drive(double hour);
private:
	double m_migration;
	double m_speed;
};