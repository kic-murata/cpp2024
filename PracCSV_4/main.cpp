#include <iostream>	//cout endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
using namespace std;
int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "エラー" << endl;
		return -1;
	}
	string text;
	getline(ifs, text);//一行目を読み捨てる
	while (getline(ifs, text)) {
		istringstream iss(text);//文字列ストリームの生成
		while (getline(iss, text, ',')) {//「,」で分割
			cout << text << " ";
		}
		cout << endl;
	}
	ifs.close();
	return 0;
}