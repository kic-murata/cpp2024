#pragma once

class Rat {
public:
	Rat();
	~Rat();
	static void showNum();//�ÓI�����o�֐�
	void squeak();
private:
	int m_id;
	static int s_count;//�ÓI�����o�ϐ�
};