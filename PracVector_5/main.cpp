#include<vector>
#include<iostream>
using namespace std;
int main() {
	vector<int> vec{ 20, 11, 9, 33, 40, 25 };
	int max, min;
	//①添え字番号を使ったループ
	max = min = vec[0]; //仮の最大値最小値を先頭要素に
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//②イテレータを使ったループ
	max = min = vec.at(0);
	for(auto itr = vec.begin(); itr != vec.end(); itr++) {
		if (max < *itr) {
			max = *itr;
		}
		if (min > *itr) {
			min = *itr;
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//③範囲forを使ったループ
	max = min = vec.front();
	for (auto d : vec) {
		if (max < d) {
			max = d;
		}
		if (min > d) {
			min = d;
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;

}