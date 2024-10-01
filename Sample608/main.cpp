#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score;
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.erase("Mike");
	score.insert(make_pair("John", 88));
	cout << "Tom�̓_����" << score["Tom"] << "�_" << endl;
	cout << "Bob�̓_����" << score["Bob"] << "�_" << endl;
	if (score.count("Mike") > 0) {
		cout << "Mike�̓_����" << score["Mike"] << "�_" << endl;
	}
	auto itr = score.find("John");
	cout << itr->first << "�̓_����" << itr->second << "�_" << endl;
	return 0;
}