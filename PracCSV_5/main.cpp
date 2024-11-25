#include <iostream>//cout, string, endl
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
		:m_name(name), m_atk(atk)
		, m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "error" << endl;
		return -1;
	}
	vector<Weapon*> vWpn{};//Weaponクラスの配列
	vector<string> v{};//一時的にCSVの各項目を格納する配列
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			v.push_back(text);//分割した項目を配列へ追加
		}
		//CSVから分割した項目をWeaponクラスのコンストラクタの引数として
		//インスタンスを生成し、そのインスタンスのアドレスをvWpnへ格納
		vWpn.push_back(new Weapon(v[0], stoi(v[1]), stoi(v[2])
			, stoi(v[3])));
		v.clear();//配列の要素をすべて削除
	}
	ifs.close();
	//武器一覧の表示：「通し番号：武器名　価格」
	for (int i = 0; i < vWpn.size(); i++) {
		//通し番号：武器名
		cout << i << ":" << left << setw(10) << vWpn[i]->getName();
		//価格
		if (vWpn[i]->getPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
		else {
			cout << right << setw(9) << "-非売品-" << endl;
		}
	}
	//武器購入画面
	cout << "どの武器を購入しますか？>";
	int i;   //購入する武器の番号を格納する変数
	cin >> i;//キーボードから数字を入力
	if (i >= 0 && i < vWpn.size()) {//武器リストの範囲内かをチェック
		if (vWpn[i]->getPrice() < 0) {//非売品のとき
			cout << "非売品のため購入できません" << endl;
		}
		else
		{ //非売品ではないときの処理
			cout << vWpn[i]->getName() << "を購入した" << endl;
			cout << "攻撃力が" << vWpn[i]->getAtk() << "アップした" << endl;
			cout << "重量が" << vWpn[i]->getWeight() << "増えた" << endl;
		}
	}
	else
	{ //武器リストの番号以外が入力されたときの処理
		cout << "その番号の武器はありません" << endl;
	}
	return 0;
}