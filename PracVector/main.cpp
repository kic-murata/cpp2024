#include <iostream>
#include <vector>
using namespace std;
void display(int max, int min) {
	cout << "最大値:" << max << endl
		<< "最小値:" << min << endl;
}
//compare(int& max, int& min, int v)
// 第1引数：最大値を格納する変数のアドレス
// 第2引数：最大値を格納する変数のアドレス
// 第3引数：比較対象の変数値
//void compare(int& max, int& min, const int& v) {
//	if (max < v) {
//		max = v;
//	}
//	if (min > v) {
//		min = v;
//	}
//}
void comparep(int* max, int* min, const int* v) {
	if (*max < *v) {
		*max = *v;
	}
	if (*min > *v) {
		*min = *v;
	}
	*v = 100;
}
int main() {
	vector<int> vec{ 20, 11, 9, 33, 40, 25 };
	int max, min;
	//ラムダ式
	auto disp = [](int a, int b) {
		cout << "最大値:" << a << endl
			<< "最小値:" << b << endl;
		};
	//auto compare = [](int& max, int& min, const int& data) {
	//	max = max < data ? data : max;
	//	min = min > data ? data : min;
	//	};
	auto compare = [&max, &min](const int& data) {
		max = max < data ? data : max;
		min = min > data ? data : min;
		};
	//添え字番号を使った最大値・最小値の検索
	max = min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		//compare(max, min, vec[i]);
		compare(vec[i]);
		//if (max < vec[i]) {
		//	max = vec[i];
		//}
		//if (min > vec[i]) {
		//	min = vec[i];
		//}
	}
//	display(max, min);
	disp(max, min);
	cout << "数値をひとつ入力:";
	int a = 0;
	cin >> a;
	vec.emplace_back(a);
	//イテレータを用いる方法
	max = min = vec[0];
	for (auto itr = vec.begin() + 1; itr != vec.end(); itr++) {
		//compare(max, min, *itr);
		compare(*itr);
		//if (max < *itr) {
		//	max = *itr;
		//}
		//if (min > *itr) {
		//	min = *itr;
		//}
	}
	display(max, min);
	cout << "数値をひとつ入力:";
	cin >> a;
	vec.emplace_back(a);
	//範囲for
	max = min = vec[0];
	for (auto d : vec) {
		[&max, &min](int i) {
			max = max < i ? i : max;
		  min = min > i ? i : min; }(d);
		//compare(d);
		//compare(max, min, d);
		//if (max < d) {
		//	max = d;
		//}
		//if (min > d) {
		//	min = d;
		//}
	}
	display(max, min);
	return 0;
}