#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"活動","activity"},
		{"雰囲気","atmosphere"},{"血液","blood"},
		{"環境","environment"},{"温度","temperature"}};

	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	uniform_int_distribution<int> dist(0, dic.size() - 1);  // 1～6 を均等な確率で得る分布生成器

	auto it = dic.begin();
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
}
