#pragma once

class Car {
public:
	Car();  //コンストラクタ
	~Car(); //デストラクタ
	double getMigration();       //ゲッター
	void setSpeed(double speed); //セッター
	void drive(double hour);
private:
	double m_migration; //総移動距離
	double m_speed;
};