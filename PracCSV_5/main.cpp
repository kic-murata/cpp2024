#include <iostream>//cout, string, endl
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
		vWpn.push_back(new Weapon(v[0], stoi(v[1]), stoi(v[2])
			, stoi(v[3])));
	}
	ifs.close();
	return 0;
}