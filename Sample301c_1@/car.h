#pragma once

class Car {
public:
	Car() = default;
	void drive(double hour);
	void setSpeed(double speed);
private:
	double m_speed;
};