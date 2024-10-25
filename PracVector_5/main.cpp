#include<vector>
#include<iostream>
using namespace std;
void compare(int& max, int& min, const int& data) {
	max = max < data ? data : max;
	min = min > data ? data : min;
	//if (max < data) {
	//	max = data;
	//}
	//if (min > data) {
	//	min = data;
	//}
}

int main() {
	vector<int> vec{ 20, 11, 9, 33, 40, 25 };
	int max, min;
	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());
	cout << "最大値:" << max << " 最小値:" << min << endl;

	//①添え字番号を使ったループ
	max = min = vec[0]; //仮の最大値最小値を先頭要素に
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//②イテレータを使ったループ
	max = min = vec.at(0);
	for(auto itr = vec.begin(); itr != vec.end(); itr++) {
		compare(max, min, *itr);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//③範囲forを使ったループ
	max = min = vec.front();
	for (auto d : vec) {
		compare(max, min, d);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;

}