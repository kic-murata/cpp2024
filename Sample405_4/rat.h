#pragma once
class Rat {
public:
	Rat();
	~Rat();
	static void showNum();//�����\��
	void squeak();
private:
	int m_id;//�l�Y�~��ID�i�ʂ��ԍ��j
	static int s_count;//�l�Y�~�̑���
};