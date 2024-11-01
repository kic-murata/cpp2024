#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy(string name, int hp, int atk, int def)
		: m_name(name), m_hp(hp), m_atk(atk), m_def(def) {};
	~Enemy() = default;
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
	void setName(string name) { m_name = name; }
	void setHp(int hp) { m_hp = hp; }
	void setAtk(int atk) { m_atk = atk; }
	void setDef(int def) { m_def = def; }
};

bool isNumber(string str) {
	for (auto c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs( filename );
	if (ifs.fail()) {
		cout << "ファイルを開けません!!" << endl;
		return -1;
	}
	string text;
	char sep = ',';
	int j = 0;
//	vector<vector<string>> vEne{};
//	vector<string> vEne{};
	vector<Enemy*> pEne{};
	vector<string> vEne{};
	while (getline(ifs, text)) {
		istringstream iss(text);
//		vEne.resize(j + 1);
		while (getline(iss, text, sep))
		{
			vEne.push_back(text);
			//vEne.push_back(text);
			//vEne[j].push_back(text);
			//cout << text << endl;
		}
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1]), stoi(vEne[2]), stoi(vEne[3])));
		vEne.clear();
		//cout << "data.size:" << vEne.size() << endl;
		//cout << "vEne.size:" << pEne.size() << endl;
		//cout << "getName:" << pEne[j]->getHp() << endl;
		//for (const auto& d : vEne) {
		//	//	for (const auto& d : vEne) {
		//	cout << d.getName << endl;
		//}
		j++;
	}
	for (const auto& p : pEne) {
		cout << p->getName() << '\t' << p->getHp() << '\t'
			<< p->getAtk() << '\t' << p->getDef() << endl;
	}
	ifs.close();
	string ofilename = "enemy_list2.csv";
	ofstream ofs(ofilename, ios::out);
	if (ofs.fail()) {
		cout << "ファイルを開けません!!" << endl;
		return -1;
	}
	for (const auto& p : pEne) {
		ofs << p->getHp() << ',' << p->getAtk() 
			<< ',' << p->getDef() << ',' << p->getName() << endl;
	}
	ofs.close();
	ofs.open(ofilename, ios::app);
	ofs << "15,10,10,Rat" << endl;
	ofs.close();
	string a0 = "2000";
	if (isNumber(a0)) {
		cout << stoi(a0);
	}
	return 0;
}