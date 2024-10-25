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
	cout << it->first << "�̓_��:"
		   << it->second << endl;
	score.erase("Mike");
	cout << "Tom�̓_��:" << score["Tom"] << endl;
	cout << "Bob�̓_��:" << score["Bob"] << endl;
	if (score.count("Mike")) {
		cout << "Mike�̓_��:" << score["Mike"] << endl;
	}
	return 0;
}