#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk)
		, m_def(def) {};
	~Enemy() = default;
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};
int main() {
	string filename = "enemy_list.csv";
	//ファイル入力用ストリームifsを生成してオープン
	ifstream ifs(filename);
	if (ifs.fail()) {//エラーチェック
		cout << "ファイルオープンエラー" << endl;
		return -1;     //エラーコード：-1
	}
	vector<Enemy*> vEne{};//Enemyクラスの配列
	vector<string> v{};//CSVの各項目を一時保存する配列
	string text;
	while (getline(ifs, text)) {//ファイルから一行読み込む
		istringstream iss(text);//文字列ストリーム生成
		while (getline(iss, text, ',')) {
			v.push_back(text);//配列に各項目を一時的に格納
		}
		//配列vの各要素をEnemyのコンストラクタの引数にして
		//インスタンス生成　※stoi()は文字列を整数に変換する
		vEne.push_back(new Enemy(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//配列vの全要素を削除
	}
	ifs.close();
	for (auto p : vEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	//出力ファイルストリームの生成
	ofstream ofs("enemy_list2.csv", ios::out);
	if (!ofs) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	ofs << "test" << "," << 100 << "," << 20 << endl;
	ofs.close();
	ofs.open("enemy_list.csv", ios::app);
	ofs << "Rat,50,5,2" << endl;
	ofs.close();
	return 0;
}