#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	//キーが文字列(string)、値が整数(int)のmapコンテナscore作成
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.insert(make_pair("John", 88));//score["John"]=88
	score.emplace("David", 70);					//score["David"]=70
	//score.erase("Mike"); //キー"Mike"と値76のペアを消去

	auto itr = score.find("John");//score中からJohnのイテレータを取得
	//mapクラスのイテレータのfirstメンバはキー、secondメンバは値
	cout << itr->first << "の点数:" << itr->second << endl;

	cout << "Tomの点数：" << score["Tom"] << endl;
	cout << "Bobの点数：" << score["Bob"] << endl;
	if (score.count("Mike")) {
		cout << "Mikeの点数：" << score["Mike"] << endl;
	}
	return 0;

}