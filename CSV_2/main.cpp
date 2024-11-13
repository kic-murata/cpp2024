#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() :m_name(""), m_hp(0), m_atk(0), m_def(0) {};
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk), m_def(def) {};
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};

int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//ファイルを開く
	if (ifs.fail()) {//ファイルが開けない場合の処理
		cout << "ファイルオープンエラー！" << endl;
		return -1; //エラーコード-1を返す
	}
	cout << "ファイルをオープン！" << endl;
	vector<string> vEne{};//1体のEnemyデータ格納用配列
	vector<Enemy*> pEne{};//Enemyクラス格納用配列
	string text;
	while (getline(ifs, text)) {	//ファイルから複数行読み込み
		istringstream iss(text);//読み込んだ文字列をストリーム変換
		while (getline(iss, text, ',')) {//文字列ストリームを','で分割
			vEne.push_back(text);//各項目を配列の各要素に格納
		}
		//stoi(文字列)は文字列をint値に変換する関数
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1]),
			stoi(vEne[2]), stoi(vEne[3])));
		vEne.clear();
	}
	ifs.close(); //開いたファイルは閉じる
	//pEneには３種類のEnemyのインスタンスのアドレスが格納されている
	for (const auto& p : pEne) {
		//ゲッターを使ってメンバ変数を取得する
		cout << p->getName() << "\t" << p->getHp() << "\t"
			 << p->getAtk() << "\t" << p->getDef() << endl;
	}
	ofstream ofs("enemy_list2.csv", ios::out);
	if (ofs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	for (const auto& p : pEne) {
		ofs << p->getDef() << "," << p->getAtk() << ","
			<< p->getHp() << "," << p->getName() << endl;
	}
	ofs.close();
	ofs.open("enemy_list.csv", ios::app);
	ofs << "Rat,15,15,3" << endl;
	ofs.close();

	return 0;
}