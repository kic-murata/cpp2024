#pragma once
class Rat {
public:
	Rat();
	~Rat();
	static void showNum();//総数表示
	void squeak();
private:
	int m_id;//ネズミのID（通し番号）
	static int s_count;//ネズミの総数
};