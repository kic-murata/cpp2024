#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score["Tom"] = 90;
	score.insert(make_pair("John", 88));
	score.emplace("David", 70);

	auto it = score.find("John");
	cout << it->first << "の点数:"
		   << it->second << endl;
	score.erase("Mike");
	cout << "Tomの点数:" << score["Tom"] << endl;
	cout << "Bobの点数:" << score["Bob"] << endl;
	if (score.count("Mike")) {
		cout << "Mikeの点数:" << score["Mike"] << endl;
	}
	return 0;
}