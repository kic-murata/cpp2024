#include <iostream>
#include <vector>
using namespace std;
void compare(int& max, int& min, int data) {
	if (max < data) {
		max = data;
	}
	if (min > data) {
		min = data;
	}
}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//①添え字の番号でループ
	max = min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "最大値:" << max << " "
		   << "最小値:" << min << endl;
	vec.push_back(0);
	//②イテレータを使ったループ
	max = min = vec.at(0);//vec[0]と同じ
	for (auto itr = vec.begin() + 1; itr != vec.end(); ++itr) {
		compare(max, min, *itr);
	}
	cout << "最大値:" << max << " "
		<< "最小値:" << min << endl;
	vec.push_back(100);
	//③範囲forを使ったループ
	max = min = vec.front();//vecの先頭要素を取得
	for (auto i : vec) {
		compare(max, min, i);
	}
	cout << "最大値:" << max << " "
	     << "最小値:" << min << endl;
	return 0;
}