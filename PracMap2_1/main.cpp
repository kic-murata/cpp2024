#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	//英単語の和訳をキー、英単語を値としてmapコンテナdicに格納
	map<string, string> dic{ {"活動","activity"}
	,{"雰囲気","atomosphere"},{"血液","blood"}
	,{"環境","environment"},{"温度","temperature"} };
	auto it = dic.begin();//先頭要素のイテレータを取得
	cout << it->first << endl;//firstがキー、secondが値
	return 0;
}