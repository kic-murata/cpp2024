#pragma once

class Car {
public:
	Car();  //�R���X�g���N�^
	~Car(); //�f�X�g���N�^
	double getMigration();       //�Q�b�^�[
	void setSpeed(double speed); //�Z�b�^�[
	void drive(double hour);
private:
	double m_migration; //���ړ�����
	double m_speed;
};