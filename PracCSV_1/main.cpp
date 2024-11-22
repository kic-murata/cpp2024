#include <iostream>	//cout
#include <fstream>	//ifstream
#include <string>		//getline
#include <sstream>	//istringstream
#include <vector>		//vector
#include <iomanip>  //setw
using namespace std;
class Weapon {
private://武器名, 攻撃力, 価格, 重量
	string m_name;
	int m_atk, m_price, m_weight;
public:
	Weapon() = default;
	//引数ありのコンストラクタでメンバ変数を初期化する
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk),
		 m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	//ファイル名を指定して入力ファイルストリームを生成
	ifstream ifs("weapon_list.csv");
	//ファイルオープン時にエラーが発生したかをチェック
	if (ifs.fail()) {
		cout << "ファイルオープンエラー" << endl;
		return -1;
	}
	//一行ずつファイルから読み込んでWeaponクラスのインスタンスを生成する
	vector<Weapon*> vWpn{};//Weaponクラスの配列
	vector<string> vec{};//CSVの各項目を一時的に格納する配列
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		//textに格納された内容を文字列ストリームとして生成
		istringstream iss(text);
		//文字列ストリームをコンマ(,)で分割するのを繰り返す
		while (getline(iss, text, ',')) {
			//分割した項目をvecに格納
			vec.push_back(text);
		}
		//CSVを分割した項目(vec)をWeaponクラスの引数として
		//コンストラクタを呼出し、インスタンスを生成する。
		//vWpnには生成されたインスタンスのアドレスが格納される。
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		//一時的に保存していた内容を削除（要素数は０）
		vec.clear();
	}
	//ファイルを閉じる
	ifs.close();
	//武器一覧の表示
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << left << setw(12) << vWpn[i]->getName();
		if (vWpn[i]->getPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
		else
		{
			cout << right << setw(9) << "-非売品-" << endl;
		}
	}
	//武器購入
	int input;
	cout << "どの武器を購入しますか？＞";
	cin >> input;
	//入力された値が武器リストの選択肢内にあるかどうかをチェック
	if (input >= 0 && input < vWpn.size()) {
		//非売品か否かのチェック
		if (vWpn[input]->getPrice() < 0) {
			cout << "非売品のため購入できません！" << endl;
		}
		else {//非売品でなかったときは購入後のメッセージを表示
			cout << vWpn[input]->getName() << "を購入しました" << endl;
			cout << "攻撃力が" << vWpn[input]->getAtk() << "アップした" << endl;
			cout << "重量が" << vWpn[input]->getWeight() << "増えた" << endl;
		}
	}
	else { //選択肢にない番号を入力したときの表示
		cout << "正しい番号を入力してください" << endl;
	}

	return 0;
}