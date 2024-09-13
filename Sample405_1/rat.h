#pragma once
class Rat {
public:
	Rat();  //コンストラクタ
	~Rat(); //デストラクタ
	static void showNum();//静的メンバ関数
	void squeak();
private:
	int m_id;
	inline static int s_count = 0;//静的メンバ変数
};