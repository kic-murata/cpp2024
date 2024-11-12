#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	//ファイル入力用ストリームifsを生成してオープン
	ifstream ifs(filename);
	if (ifs.fail()) {//エラーチェック
		cout << "ファイルオープンエラー" << endl;
		return -1;     //エラーコード：-1
	}
	string text;
	getline(ifs, text);//ファイルから一行読み込む
	istringstream iss(text);//文字列ストリーム生成
	getline(iss, text, ',');
	cout << text << endl;
	return 0;
}