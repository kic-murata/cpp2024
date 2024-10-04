#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v1{ 10,9,8 };
	vector<string> v2;
	if (v1.empty()) {
		cout << "配列は空です" << endl;
	}
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back("ABC");
	v2.push_back("DEF");
	cout << "v1の要素数は" << v1.size() << endl;

	vector<int>::iterator itrV1;
	itrV1 = v1.begin();
	cout << "itrV1の値は" << *itrV1 << endl;
	v1.erase(itrV1);


	v1.pop_back();
	v1.emplace_back(4);
	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}
	cout << "v1の要素数は" << v1.size() << endl;
	cout << "v2の要素数は" << v2.size() << endl;
	v2.pop_back();
	v2.emplace_back("G");
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	cout << "v2の要素数は" << v2.size() << endl;
	return 0;
}