#include <iostream>	//cout
#include <fstream>	//ifstream
#include <string>		//getline
#include <sstream>	//istringstream
#include <vector>		//vector
using namespace std;
class Weapon {
private://武器名, 攻撃力, 価格, 重量
	string m_name;
	int m_atk, m_price, m_weight;
public:
	Weapon() = default;
	//引数ありのコンストラクタでメンバ変数を初期化する
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk),
		 m_price(price), m_weight(weight) {};
	~Weapon() = default;
};

int main() {
	//ファイル名を指定して入力ファイルストリームを生成
	ifstream ifs("weapon_list.csv");
	//ファイルオープン時にエラーが発生したかをチェック
	if (ifs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	//一行ずつファイルから読み込んで表示を繰り返す
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		//textに格納された内容を文字列ストリームとして生成
		istringstream iss(text);
		//文字列ストリームをコンマ(,)で分割するのを繰り返す
		while (getline(iss, text, ',')) {
			//分割した項目と空白を表示
			cout << text << " ";
		}
		//改行を表示
		cout << endl;
	}
	//ファイルを閉じる
	ifs.close();
	return 0;
}