#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"活動","activity"},
		{"雰囲気","atmosphere"},{"血液","blood"},
		{"環境","environment"},{"温度","temperature"}};

	cout << dic.begin()->first << endl;
//	for (auto p : dic) {
	for(auto it = dic.begin(); it != dic.end(); it++){
		cout << "キー：" << it->first << endl;
	}


	//乱数生成
	random_device rand_dev{}; //乱数生成器を作成
	mt19937 rand_engine(rand_dev());//アルゴリズムにメルセンヌツイスターを使う
	uniform_int_distribution<int> dist(0, dic.size() - 1);  // 0～mapの要素数-1 を均等な確率で得る分布生成器

	//mapの先頭のイテレータ取得
	auto it = dic.begin();
	//乱数とnext関数を使ってイテレータを更新
	it = next(it, dist(rand_engine));
	cout << it->first << "を英語に直すと？";
	string input;
	cin >> input;
	if (input == it->second) {
		cout << "正解！" << endl;
	}
	else {
		cout << "不正解" << endl;
	}

	map<int, map<string, int>> 
		tMap{ { 1, { {"abc", 3} } }, { 2, { {"abc", 1} } },
					{ 3, { {"def", 9} } }, { 4, { {"def", 7} } }
	};
	cout << tMap[1]["abc"] << endl;
	cout << tMap[2]["abc"] << endl;
	cout << tMap[3]["def"] << endl;
	cout << tMap[4]["def"] << endl;

	return 0;
}
