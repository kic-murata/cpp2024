#include <vector>
#include <iostream>
using namespace std;
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//①添え字の番号でループ
	max = min = vec[0]; //仮の最大値と最小値を先頭要素に
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	vec.emplace_back(50);
	//②イテレータでループ
	max = min = vec.at(0);//vec[0]とvec.at(0)は同じ意味
}