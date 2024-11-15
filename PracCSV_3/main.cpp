#include <iostream>//cout, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
#include <vector>  //vector
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
		vWpn.push_back(new Weapon(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//配列vの要素を全削除
	}
	ifs.close();
	return 0;
}