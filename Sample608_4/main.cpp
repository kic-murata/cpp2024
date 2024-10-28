#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.insert(make_pair("John", 88));//ペアの挿入１
	score.emplace("David", 90);	//ペアの挿入２
	score.erase("Mike");				//ペアの削除
	cout << "Tomの点数:" << score["Tom"] << endl;
	cout << "Bobの点数:" << score["Bob"] << endl;
	if (score.count("Mike")) {	//キーの有無のチェック
		cout << "Mikeの点数:" << score["Mike"] << endl;
	}
	auto itr = score.find("John");
	//firstメンバ：キー　　secondメンバ：値（value）
	cout << itr->first << "の点数:" << itr->second << endl;
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