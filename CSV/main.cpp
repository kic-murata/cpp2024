#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs( filename );
	if (ifs.fail()) {
		cout << "ファイルを開けません!!" << endl;
		return -1;
	}
	string text;
	char sep = ',';
	int j = 0;
	vector<vector<string>> vEne{};
//	vector<string> vEne{};
	while (getline(ifs, text)) {
		istringstream iss(text);
		vEne.resize(j + 1);
		while (getline(iss, text, sep))
		{
			//		vEne.push_back(text);
			vEne[j].push_back(text);
			//cout << text << endl;
		}
		for (const auto& d : vEne[j]) {
			//	for (const auto& d : vEne) {
			cout << d << endl;
		}
		j++;
	}
	ifs.close();
	string a0 = "aa0a";
	for (auto c : a0) {
		if (!isdigit(c)) {
			cout << "変換不可" << endl;
		}
	}
	return 0;
}