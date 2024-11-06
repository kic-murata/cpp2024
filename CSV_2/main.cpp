#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//ファイルを開く
	if (ifs.fail()) {//ファイルが開けない場合の処理
		cout << "ファイルオープンエラー！" << endl;
		return -1; //エラーコード-1を返す
	}
	cout << "ファイルをオープン！" << endl;
	vector<vector<string>> vEne{};//Enemyデータ格納用配列
	string text;
	int j = 0;//行番号管理用変数
	while (getline(ifs, text)) {	//ファイルから複数行読み込み
		istringstream iss(text);//読み込んだ文字列をストリーム変換
		vEne.resize(j+1); //vEne[j]の領域を作る
		while (getline(iss, text, ',')) {//文字列ストリームを','で分割
			vEne[j].push_back(text);//各項目を配列の各要素に格納
		}
		for (auto d : vEne[j]) {//範囲forでvEneの各要素をdに代入
			cout << d << endl;
		}
		j++;
	}
	ifs.close(); //開いたファイルは閉じる
	return 0;
}