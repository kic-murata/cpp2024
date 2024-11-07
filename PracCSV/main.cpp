#include <iostream>
#include <fstream>
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
	getline(ifs, text);
	while (getline(ifs, text)) {
		cout << text << endl;
	}
	ifs.close();
	return 0;
}