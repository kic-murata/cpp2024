#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"活動","activity"},
		{"雰囲気","atmosphere"},{"血液","blood"},
		{"環境","environment"},{"温度","temperature"}};

	//auto it = dic.begin();
	//cout << it->first << endl;
	//cout << dic.begin()->first << endl;
	//イテレータを使ったループ
	//for (auto it = dic.begin(); it != dic.end(); it++) {
	//	cout << it->first << endl;
	//}
	//範囲for
	//for (auto p : dic) {
	//	cout << p.first << endl;
	//}

	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	uniform_int_distribution<int> 
													dist(0, dic.size() - 1);
	//先頭イテレータの取得
	auto it = dic.begin();
	//乱数ぶんイテレータを進める
	it = next(it, dist(rand_engine));
	cout << it->first << "の英単語は？" << endl;
	string input;
	cin >> input;
	if (input == it->second) {
		cout << "正解！" << endl;
	}
	else {
		cout << "不正解…" << endl;
	}

	return 0;
}
