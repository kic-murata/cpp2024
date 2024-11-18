#include <iostream>
#include <fstream>//ファイルストリーム
#include <sstream>//文字列ストリーム
#include <string>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;//デフォルトコンストラクタ
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp)
		, m_atk(atk), m_def(def) {};
	~Enemy() = default;//デフォルトデストラクタ
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};


int main() {
	//ファイル読み込み用ストリームの生成
	ifstream ifs("enemy_list.csv");
	if (ifs.fail()) {//ファイルオープンに失敗
		cout << "ファイルオープンエラー" << endl;
		return -1;		 //エラーコード-1
	}
	vector<Enemy*> vEne{};//Enemyクラスの配列
	vector<string> v{};//CSVの各項目を格納する配列
	//int j = 0;//行番号管理用j
	string text;
	while (getline(ifs, text)) {//一行読み込んでtextへ
		//vEne.resize(j + 1);//vEneに一行分の領域を追加
		istringstream iss(text);//文字列ストリーム生成
		while (getline(iss, text, ',')) {//「,」で分割
			v.push_back(text);
		}
		//stoi: 文字列を整数値に変換
		vEne.push_back(new Enemy(v[0], stoi(v[1])
			, stoi(v[2]), stoi(v[3])));
		v.clear();//全要素を削除
		//j++;
	}
	ifs.close();
	//vEne.size(): 　　行数を取得できる
	//vEne[0].size():　列数を取得できる
	//for (int i = 0; i < vEne.size(); i++) {
	//	for (int j = 0; j < vEne[0].size(); j++) {
	//		cout << vEne[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	for (auto p : vEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	return 0;
}