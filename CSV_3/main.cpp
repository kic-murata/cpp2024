#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルを開けません！" << endl;
		return -1;
	}
	vector<string> vEne{};//一次元配列の宣言
	string text;
	getline(ifs, text);//一行だけCSVから読み込む
	istringstream iss(text);//文字列ストリームに変換
	while (getline(iss, text, ',')) {//文字列ストリームを','で分割
		vEne.push_back(text);//分割した項目を配列へ格納
	}
	ifs.close();
	for (auto d : vEne) {//範囲forで配列の全要素を表示
		cout << d << endl;
	}
	return 0;
}