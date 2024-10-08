#pragma once

class Car {
public:
	Car();  //コンストラクタ
	~Car(); //デストラクタ
//	virtual ~Car(); //デストラクタ
	void setSpeed(double speed);
	double getSpeed();
	double getMigration();
	void drive(double hour);
private:
	double m_speed;
protected:
	double m_migration;
};