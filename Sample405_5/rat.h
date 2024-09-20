#pragma once

class Rat {
public:
	Rat();
	~Rat();
	static void showNum();//静的メンバ関数
	void squeak();
private:
	int m_id;
	static int s_count;//静的メンバ変数
};