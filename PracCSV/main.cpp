#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	string filename = "weapon_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルが開けません!" << endl;
		return -1;
	}
	string text;
	getline(ifs, text);//先頭行を読み飛ばし
	while (getline(ifs, text)) {//ファイル末尾まで一行ずつ読み込む
		istringstream iss(text);//文字列ストリームに変換
		while(getline(iss, text, ',')) {//文字列ストリームを,で分割
			cout << text << " ";
		}
		cout << endl;
	}
	ifs.close();
	return 0;
}