#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//添え字を使ったループ
	max = min = vec[0];//仮の最大値最小値
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//イテレータを使ったループ
	max = min = vec[0];//仮の最大値最小値
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//範囲forを使ったループ
	max = min = vec[0];//仮の最大値最小値
	cout << "最大値:" << max << " 最小値:" << min << endl;
	return 0;
}