#pragma once

class Car {
public:
	Car();  //コンストラクタ
	~Car(); //デストラクタ
	double getMigration();
	void setSpeed(double speed);
	void drive(double hour);
private:
	double m_migration;
	double m_speed;
};