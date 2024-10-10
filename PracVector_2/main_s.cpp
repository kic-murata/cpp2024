#include <iostream>
#include <vector>
using namespace std;
//参照渡しを用いたcompare関数
//void compare(int& max, int& min, int data) {
//	max = max < data ? data : max;
//	min = min > data ? data : min;
//}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//ラムダ式を用いたcompare関数
	auto compare = [](int& max, int& min, int data) { 
		max = max < data ? data : max; 
		min = min > data ? data : min; 
	};
	//*** 添え字を使ったループ
	max = min = vec[0];			//仮の最大値最小値として先頭要素を代入
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//*** イテレータを使ったループ
	vec.push_back(-10);			//データ(-10)を追加
	max = min = vec.at(0);	//仮の最大値最小値として先頭要素を代入
	for(auto itr = vec.begin(); itr != vec.end(); ++itr){
		compare(max, min, *itr);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//*** 範囲forを使ったループ
	vec.push_back(50);			//データ(50)を追加
	max = min = vec.front();//仮の最大値最小値として先頭要素を代入
	for (auto itr : vec) {
		compare(max, min, itr);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	return 0;
}