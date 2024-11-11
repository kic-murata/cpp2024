#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.txt";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "ファイルを開けません" << endl;
		return -1;//エラーコード:-1
	}

	return 0;
}