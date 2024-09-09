#pragma once

class Car {
public:
	Car();  //コンストラクタ[クラス名+()]
	~Car(); //デストラクタ[~クラス名+()]
	double getMigration();
	void setSpeed(double speed);
	void drive(double hour);
private:
	double m_migration;
	double m_speed;
};