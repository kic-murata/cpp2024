#pragma once

class Rat {
public:
	Rat(); //�R���X�g���N�^
	~Rat();//�f�X�g���N�^
	static void showNum();//�ÓI�����o�֐�
	void squeak(); //�C���X�^���X�����o�֐�
private:
	int m_id;      //�C���X�^���X�����o�ϐ�
	inline static int s_count = 0; //�ÓI�����o�ϐ�
};