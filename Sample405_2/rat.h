#pragma once

class Rat {
public:
	Rat();                 //コンストラクタ
	~Rat();                //デストラクタ
	static void showNum(); //ネズミの数を出力（静的メンバ）
	void squeak();         //ネズミが鳴く
private:
	int m_id;           //ネズミのID番号
	static int s_count; //ネズミの数（静的メンバ）
};