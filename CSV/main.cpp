#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
bool isNumber(string str) {
	for (auto c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
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
	string a0 = "2000";
	if (isNumber(a0)) {
		cout << stoi(a0);
	}
	return 0;
}