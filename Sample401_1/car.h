#pragma once

class Car {
public:
	Car();  //�R���X�g���N�^
	~Car(); //�f�X�g���N�^
	void setSpeed(double speed);
	double getSpeed();
	double getMigration();
	void drive(double hour);
private:
	double m_speed;
	double m_migration;
};