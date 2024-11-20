#include <iostream>//cout, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
#include <vector>  //vector
#include <iomanip> //setw
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
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "OpenError" << endl;
		return -1;
	}
	vector<string> v{};//CSVの各項目を保存する配列
	vector<Weapon*> vWpn{};//Weaponクラス用の配列
	string text;
	getline(ifs, text);//一行（見出し）読み捨てる
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			v.push_back(text);//CSVの各項目をvに追加
		}
		//CSVの各要素をWeaponクラスのコンストラクタの引数にする。
		//生成されたインスタンスのアドレスをvWpnに格納する。
		vWpn.push_back(new Weapon(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//配列vの要素を全削除
	}
	ifs.close();
	//武器一覧の表示
	for (int i = 0; i < vWpn.size(); i++) {
		//通し番号：武器名　の表示
		cout << i << ":"
			<< left << setw(12) << vWpn[i]->getName();
		//価格　の表示（価格が負の数なら非売品）
		if (vWpn[i]->getPrice() < 0) {
			cout << right << setw(11) << "非売品" << endl;
		} else
		{ 
			cout << right << setw(10) 
				<< vWpn[i]->getPrice() << "G" << endl;
		}
	}
	cout << "どの武器を購入しますか？＞";
	int no;
	cin >> no; //キーボードからの入力をnoに格納
	//noの有効範囲チェック
	if (no >= 0 && no < vWpn.size()) {
		if (vWpn[no]->getPrice() < 0) {
			cout << "非売品のため購入できません" << endl;
		}
		else
		{
			cout << vWpn[no]->getName() << "を購入した" << endl
			<< "攻撃力が" << vWpn[no]->getAtk() << "アップ" << endl
			<< "重量が" << vWpn[no]->getWeight() << "増えた" << endl;
		}
	}
	else
	{
		cout << "その武器は購入できません" << endl;
		cout << "0～" << vWpn.size() - 1 << "の範囲で入力してください";
	}

	return 0;
}