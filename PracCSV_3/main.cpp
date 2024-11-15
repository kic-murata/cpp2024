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
	vector<string> v{};//CSV�̊e���ڂ�ۑ�����z��
	vector<Weapon*> vWpn{};//Weapon�N���X�p�̔z��
	string text;
	getline(ifs, text);//��s�i���o���j�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			v.push_back(text);//CSV�̊e���ڂ�v�ɒǉ�
		}
		vWpn.push_back(new Weapon(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//�z��v�̗v�f��S�폜
	}
	ifs.close();
	return 0;
}