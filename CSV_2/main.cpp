#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//ファイルを開く
	if (ifs.fail()) {//ファイルが開けない場合の処理
		cout << "ファイルオープンエラー！" << endl;
		return -1; //エラーコード-1を返す
	}
	cout << "ファイルをオープン！" << endl;
	string text;
	while (getline(ifs, text,',')) {//ファイルから一行読み込む
		cout << text << endl;
	}
	ifs.close(); //開いたファイルは閉じる
	return 0;
}