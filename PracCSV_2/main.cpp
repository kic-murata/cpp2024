#include <iostream>	//cout,endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
#include <vector>		//vector
using namespace std;
class Weapon {
private:
	string m_name;
	int m_atk, m_price, m_weight;
public:
	Weapon() = default;
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk), m_price(price)
		, m_weight(weight) {};
	string getName() { return m_name; }	
	int getAtk()     { return m_atk; }
	int getPrice()   { return m_price; }
	int getWeight()  { return m_weight; }
	~Weapon() = default;
};

int main() {
	//ファイル名を指定して入力用ファイルストリームifsを生成
	ifstream ifs("weapon_list.csv");
	//ファイルが開けたかどうかのチェック
	if (ifs.fail()) { //エラー時の処理
		cout << "ファイルオープンエラー" << endl;
		return -1;			//エラーコード-1で終了
	}
	//if(!ifs){ エラー時の処理 }←この書き方でもOK
	
	//ファイルから一行ずつ読み込んで表示を繰り返し実行
	string text;
	vector<string> vec{};//一時的にCSVの各項目を保存する配列
	vector<Weapon*> vWpn{};//Weaponクラスの配列
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {//一行読み取ってtextへ
		istringstream iss(text); //文字列ストリームiss生成
		while (getline(iss, text, ',')) {//コンマで分割
			vec.push_back(text);//分割した項目を配列vecに格納
		}
		//vecの要素をWeaponクラスのコンストラクタの引数にする
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		vec.clear();//一行分の内容を消去
	}
	ifs.close();
	return 0;
}