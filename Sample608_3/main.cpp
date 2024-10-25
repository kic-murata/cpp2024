#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.erase("Mike"); //�L�[�l"Mike"�Ƃ��̒l������
	score.insert(make_pair("John", 88));
	score.emplace("David", 70);
	auto itr = score.find("John");
	cout << itr->first << "�̓_��:" << itr->second << endl;
	cout << "Tom�̓_��:" << score["Tom"] << endl;
	cout << "Bob�̓_��:" << score["Bob"] << endl;
	if (score.count("Mike")) {
		cout << "Mike�̓_��:" << score["Mike"] << endl;
	}
	//for (auto it = score.begin(); it != score.end(); it++) {
	//	cout << "Key: " << it->first << " "
	//		  << "Value:" << it->second << endl;
	//}
	//for (auto p : score) {
	//		cout << "Key: " << p.first << " "
	//			  << "Value:" << p.second << endl;
	//}
	for (const auto& [key, value] : score) {
		cout << "Key: " << key << " "
			<< "Value:" << value << endl;
	}

	return 0;
}