#pragma once

class Car {
public:
	Car();  //コンストラクタ
	virtual ~Car(); //デストラクタ
	void setSpeed(double speed);
	double getSpeed();
	double getMigration();
	void drive(double hour);
private:
	double m_speed;
	double m_migration;
};