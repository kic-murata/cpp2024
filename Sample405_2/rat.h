#pragma once

class Rat {
public:
	Rat();                 //�R���X�g���N�^
	~Rat();                //�f�X�g���N�^
	static void showNum(); //�l�Y�~�̐����o�́i�ÓI�����o�j
	void squeak();         //�l�Y�~����
private:
	int m_id;           //�l�Y�~��ID�ԍ�
	static int s_count; //�l�Y�~�̐��i�ÓI�����o�j
};