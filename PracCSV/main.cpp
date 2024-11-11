#include <iostream>//cout, cin, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
#include <vector>  //vector<>
#include <ios>     //left, right
#include <iomanip> //setw
using namespace std;
class Weapon {
private:
	string m_name;
	int m_atk;
	int m_price;
	int m_weight;
public:
	Weapon() : m_name(""), m_atk(0), m_price(0), m_weight(0) {};
	Weapon(string name, int atk, int price, int weight)
		: m_name(name), m_atk(atk), m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};
int main() {
	string filename = "weapon_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルが開けません!" << endl;
		return -1;
	}
	vector<Weapon*> vWpn{};
	vector<string> vec{};
	string text;
	getline(ifs, text);//先頭行を読み飛ばし
	while (getline(ifs, text)) {//ファイル末尾まで一行ずつ読み込む
		istringstream iss(text);//文字列ストリームに変換
		while(getline(iss, text, ',')) {//文字列ストリームを,で分割
			vec.push_back(text);
		//	cout << text << " ";
		}
		//cout << endl;
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]), stoi(vec[2]), stoi(vec[3])));
		vec.clear();
	}
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << vWpn[i]->getName() << "\t";
		if (vWpn[i]->getPrice() < 0) {
			cout << right << setw(9) << "-非売品-" << endl;
		}//right は右揃え setw(数値)は表示桁数
		else {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
	}
	cout << "どの武器を購入しますか？＞";
	cin >> text;	//キーボードから入力
	int sel = stoi(text);//文字を数値に変換
	if (sel >= 0 && sel < vWpn.size()) {//選択肢の範囲チェック
		if(vWpn[sel]->getPrice() >= 0){//非売品でなければ
			cout << vWpn[sel]->getName() << "を購入した" << endl
				<< "攻撃力が" << vWpn[sel]->getAtk() << "アップした" << endl
				<< "重量が" << vWpn[sel]->getWeight() << "増えた" << endl;
		}
		else {//非売品の場合
			cout << "購入できません" << endl;
		}
	}
	else {//選択肢の範囲外を入力した場合
		cout << "番号がありません" << endl;
	}
	ifs.close();
	return 0;
}