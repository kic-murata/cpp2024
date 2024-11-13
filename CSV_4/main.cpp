#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルを開けません" << endl;
		return -1;//エラーコード:-1
	}
	string text;
	getline(ifs, text);//一行ぶん読み取ってtextへ格納
	istringstream iss(text);//文字列ストリームに変換
	while (getline(iss, text, ',')) {//ストリームを[,]で分割
		cout << text << endl;
	}
	ifs.close();//ファイルを閉じる
	return 0;
}