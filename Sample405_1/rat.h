#pragma once
class Rat {
public:
	Rat();  //�R���X�g���N�^
	~Rat(); //�f�X�g���N�^
	static void showNum();//�ÓI�����o�֐�
	void squeak();
private:
	int m_id;
	inline static int s_count = 0;//�ÓI�����o�ϐ�
};