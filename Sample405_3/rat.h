#pragma once

class Rat {
public:
	Rat(); //�R���X�g���N�^
	~Rat();//�f�X�g���N�^
	static void showNum();//�ÓI�����o�֐�
	void squeak(); //�C���X�^���X�����o�֐�
private:
	int m_id;      //�C���X�^���X�����o�ϐ�
	static int s_count; //�ÓI�����o�ϐ�
};