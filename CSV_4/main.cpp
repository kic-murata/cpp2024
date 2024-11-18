#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def)
		:m_name(name),m_hp(hp),m_atk(atk),m_def(def) {};
	~Enemy() = default;
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルを開けません" << endl;
		return -1;//エラーコード:-1
	}
	vector<string> vEne{};
	vector<Enemy*> pEne{};
	string text;
	while (getline(ifs, text)) {//一行ぶん読み取ってtextへ格納
		istringstream iss(text);//文字列ストリームに変換
		while (getline(iss, text, ',')) {//ストリームを[,]で分割
			vEne.push_back(text);
		}
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1])
			, stoi(vEne[2]), stoi(vEne[3])));
		//stoi: 文字列を整数値に変換する関数
		vEne.clear();//vEneの全要素を削除
	}
	ifs.close();//ファイルを閉じる
	for (auto p : pEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	//test.csvを上書きモードでオープンする
	ofstream ofs("test.csv", ios::out);
	if (ofs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	ofs << "test" <<endl;
	ofs.close();
	//既存のenemy_list.csvに追記する
	ofs.open(filename, ios::app);
	ofs << pEne[0]->getName() << ","
		<< pEne[0]->getHp() << ","
		<< pEne[0]->getAtk() << ","
		<< pEne[0]->getDef() << endl;
	ofs.close();
	return 0;
}