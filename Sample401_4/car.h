#pragma once

class Car {
public:
	Car();  //�R���X�g���N�^[�N���X��+()]
	~Car(); //�f�X�g���N�^[~�N���X��+()]
	double getMigration();
	void setSpeed(double speed);
	void drive(double hour);
private:
	double m_migration;
	double m_speed;
};