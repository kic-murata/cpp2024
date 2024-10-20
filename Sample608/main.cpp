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
	if (score.count("John")) {//Johnのキーが存在していれば1を返す（ないと0）
		cout << "----" << endl;
		auto itr = score.find("John");//Johnのキーのイテレータを返す
		cout << itr->first << "の点数は" << itr->second << "点" << endl;
		cout << "----" << endl;
	}
	for (const auto& [text, i] : score) {
		cout << text << " " << i <<  endl;
	}
	score.emplace("Michael", 70);//emplaceの場合、pairは不要
	score.insert(pair("AAA",10));//イテレータ不要（勝手にソートされるため）
	for (auto itr = begin(score); itr != end(score); itr++)
	{
		cout << itr->first << "," << itr->second << endl;
	}
	return 0;
}