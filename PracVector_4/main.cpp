#include <iostream>
#include <vector>
using namespace std;
void compare(int& max, int& min, const int& data) {
	max = max < data ? data : max;
	min = min > data ? data : min;
}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());
	cout << "最大値:" << max << " 最小値:" << min << endl;

	//①添え字番号を使ったループ
	max = min = vec[0];//仮の最大値と最小値を設定
	for (int i = 1; i < vec.size(); i++) { //添え字番号iでループ
		compare(max, min, vec[i]); //compare関数呼出し
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//②イテレータを使ったループ
	max = min = vec.at(0);//仮の最大値と最小値を設定
	for (auto itr = vec.begin(); itr != vec.end(); itr++) { //イテレータでループ
		compare(max, min, *itr); //compare関数呼出し
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//③範囲forを使ったループ
	max = min = vec.front();//仮の最大値と最小値を設定
	for (auto d : vec) { //範囲forでループ
		compare(max, min, d); //compare関数呼出し
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
}