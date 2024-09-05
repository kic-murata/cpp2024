#pragma once

class Car {
public:
	Car();
	~Car();
	double getMigration();
	double getSpeed();
	void drive(double hour);
	void setSpeed(double speed);
private:
	double m_speed;
	double m_migration;
};
