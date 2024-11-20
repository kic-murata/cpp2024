#include <iostream>	//cout endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
#include <vector>		//vector
using namespace std;
//Weaponクラスの定義と実装
class Weapon {
private://(string)武器名、(int)攻撃力、価格、重量を格納
	string m_name;
	int m_atk, m_price, m_weight;
public://コンストラクタ/デストラクタ/ゲッター
	Weapon() = default;
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk), m_price(price),
		m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};
int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "エラー" << endl;
		return -1;
	}
	vector<string> vec{};  //CSVデータの一時保存用配列
	vector<Weapon*> vWpn{};//Weaponクラス用の配列
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		istringstream iss(text);//文字列ストリームの生成
		while (getline(iss, text, ',')) {//「,」で分割
			vec.push_back(text);//CSVの各項目を格納
		}
		//vec配列の要素を引数としてWeaponクラスのコンストラクタを
		//実行し、その結果得られたインスタンスのアドレスを格納
		vWpn.push_back(new Weapon(vec[0],stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		vec.clear();//一時的に保存してた内容を全削除（要素数０）
	}
	ifs.close();
	//武器一覧の表示
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << vWpn[i]->getName();
		if (vWpn[i]->getPrice() < 0) {
			cout << "非売品" << endl;
		}
		else
		{
			cout << vWpn[i]->getPrice() << "G" << endl;
		}
	}
	return 0;
}