#include <iostream>
#include <vector>
using namespace std;
void compare(int& max, int& min, int data) {
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
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//添え字を使ったループ
	max = min = vec[0];//仮の最大値最小値
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
		//max = max < vec[i] ? vec[i] : max;
		//min = min > vec[i] ? vec[i] : min;
		//if (max < vec[i]) {
		//	max = vec[i];
		//}
		//if (min > vec[i]) {
		//	min = vec[i];
		//}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//イテレータを使ったループ
	vec.push_back(-10);
	//max = min = vec[0];//仮の最大値最小値
	max = min = vec.at(0);
	for(auto itr = vec.begin();itr!=vec.end();++itr){
		for (int i = 1; i < vec.size(); i++) {
			compare(max, min, *itr);
			//if (max < *itr) {
			//	max = *itr;
			//}
			//if (min > *itr) {
			//	min = *itr;
			//}
		}
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	//範囲forを使ったループ
	vec.push_back(50);
	max = min = vec.front();//仮の最大値最小値
	for (auto itr : vec) {
		compare(max, min, itr);
	}
	cout << "最大値:" << max << " 最小値:" << min << endl;
	return 0;
}