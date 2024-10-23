#include <iostream>
#include <string>
#include <iomanip>
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
	//c++17以降でできるようになった方法
	//ここから
	for (const auto& [key, value] : score) {
		cout << key << " " << value <<  endl;
	}
	//ここまで
	score.emplace("Michael", 70);//emplaceの場合、pairは不要
	score.insert(pair("AAA",10));//イテレータ不要（勝手にソートされるため）
	for (auto itr = begin(score); itr != end(score); itr++)
	{
		cout << itr->first << "," << itr->second << endl;
	}

	for (auto it = score.begin(); it != score.end(); it++) {
		cout << "キー:" << it->first << " 値:" << it->second << endl;
	}
	for (auto p : score) {
		cout << "キー:" << p.first << " 値:" << p.second << endl;
	}

	string input;
	cin >> input;
	if (score.count(input)) {
		cout << score[input] << endl;
	}
	map<string, string> ai{ {"山","川"},{"月","星"} };
	for (auto p : ai) {
		cout << p.first << " といえば " << p.second << endl;
	}
	map<int, double> root{ {2,1.41421356},{3,1.7320504} };
	for (auto p : root) {
		cout << p.first << " の平方根は " << setprecision(6) << p.second << endl;
	}




	return 0;
}