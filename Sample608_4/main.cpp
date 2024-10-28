#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.insert(make_pair("John", 88));//�y�A�̑}���P
	score.emplace("David", 90);	//�y�A�̑}���Q
	score.erase("Mike");				//�y�A�̍폜
	cout << "Tom�̓_��:" << score["Tom"] << endl;
	cout << "Bob�̓_��:" << score["Bob"] << endl;
	if (score.count("Mike")) {	//�L�[�̗L���̃`�F�b�N
		cout << "Mike�̓_��:" << score["Mike"] << endl;
	}
	auto itr = score.find("John");
	//first�����o�F�L�[�@�@second�����o�F�l�ivalue�j
	cout << itr->first << "�̓_��:" << itr->second << endl;
	//for (auto d : score) {
	//	cout << "Key:" << d.first
	//		<< " Value:" << d.second << endl;
	//}
	for (const auto& [key, value] : score) {
		cout << "Key:" << key
			<< " Value:" << value << endl;
	}
	return 0;
}