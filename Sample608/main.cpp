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
	cout << "Tomの点数は" << score["Tom"] << "点" << endl;
	cout << "Bobの点数は" << score["Bob"] << "点" << endl;
	if (score.count("Mike") > 0) {
		cout << "Mikeの点数は" << score["Mike"] << "点" << endl;
	}
	auto itr = score.find("John");
	cout << itr->first << "の点数は" << itr->second << "点" << endl;
	return 0;
}