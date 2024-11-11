#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score;//mapコンテナのインスタンス生成
	score["Tom"] = 100;//キー:Tom 値:100のペアをscoreに追加
	score["Bob"] = 80; //キー:Bob 値:80のペアをscoreに追加
	score["Mike"] = 76;//キー:Mike 値:76のペアをscoreに追加
	score.emplace("David", 90);//キー:David 値:90をscoreに挿入
	score.insert({ "John", 70 });//キー:John 値:70をscoreに挿入
	//イテレータを使ったscore全要素の表示
	for (auto it = score.begin(); it != score.end(); it++) {
		//first：キー(Key)　second：値(Value)
		cout << it->first << ":" << it->second << endl;
	}
	////範囲forを使った表示
	//for (auto p : score) {
	//	cout << p.first << ":" << p.second << endl;
	//}
	score.erase("Mike");//キー:Mikeのデータをscoreから削除

	cout << "Tomの点数：" << score["Tom"] << endl;
	cout << "Bobの点数：" << score["Bob"] << endl;
	
	if (score.count("Mike")) {//Mikeのキーの存在をチェック
		cout << "Mikeの点数：" << score["Mike"] << endl;
	}
	auto it = score.find("David");//Davidのキーの場所をイテレータで取得
	cout << it->first << "の点数：" << it->second << endl;

	//C++17以降対応
	//for (const auto& [key, value] : score) {
	//	cout << "key:" << key << endl
	//		<< "value:" << value << endl;
	//}

	return 0;
}