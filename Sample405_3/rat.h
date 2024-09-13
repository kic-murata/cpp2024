#pragma once

class Rat {
public:
	Rat(); //コンストラクタ
	~Rat();//デストラクタ
	static void showNum();//静的メンバ関数
	void squeak(); //インスタンスメンバ関数
private:
	int m_id;      //インスタンスメンバ変数
	static int s_count; //静的メンバ変数
};