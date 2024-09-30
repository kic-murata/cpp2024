#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;
int main()
{
	array<int,3> arr{ 1,2,3 };
	vector<int> intVec;
	vector<int> intVec2{ 99,98,97 };
	vector<string> strVec;
	cout << arr[0] << endl;
	cout << arr.at(1) << endl;
	//arr.swap(0, 1);
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	arr.fill(100);
	//cout << arr.fill(100) << endl;
	cout << arr.at(1) << endl;
	if (intVec.empty()) {
		cout << "intVecは空の配列" << endl;
		cout << "capa:" << intVec.capacity() << endl;
	}
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
	cout << "capa:" << intVec.capacity() << endl;
	intVec2.emplace(intVec2.begin()+2,100);
	strVec.push_back("ABC");
	strVec.push_back("DEF");
	for (const auto& v : intVec) {
		cout << v << " " << endl;
	}
	cout << "intVec1.size=" << intVec.size() << endl;
	intVec.insert(intVec.begin()+1, 11);
	cout << "intVec1.size=" << intVec.size() << endl;
	for (const auto& v : intVec2) {
		cout << v << " " << endl;
	}
	cout << "intVec2.size=" << intVec2.size() << endl;
	cout << "intVec1.size=" << intVec.size() << endl;
	intVec.pop_back();
	cout << "intVec1.size=" << intVec.size() << endl;
	for (const auto& v : intVec) {
		cout << v << " " << endl;
	}
	//for (auto i = intVec.begin(); i < intVec.end(); i++) {
	//	cout << "intVec[" << i << "]=" << intVec[i] << endl;
	//}
	strVec.pop_back();
	strVec.emplace_back("G");
	//vector<int>::iterator itrInt = intVec.begin();
	auto itrInt = intVec.begin();
	cout << "*itr=" << *(itrInt+2) << endl;
	intVec.insert(itrInt + 1, 111);
	intVec.erase(itrInt + 2);
	for (int i = 0; i < intVec.size(); i++) {
	//	cout << "intVec[" << i << "]=" << intVec[i] << endl;
		cout << "intVec[" << i << "]=" << intVec.at(i) << endl;
	}
	cout << "イテレータを使った表示" << endl;
	for (auto itrInt = intVec.begin()+1; itrInt != intVec.end(); itrInt++) {
		cout << *itrInt << endl;
	}
	cout << "範囲for文を使った表示" << endl;
	for (auto itr : intVec) {
		cout << itr << endl;
	}
	for (int i = 0; i < strVec.size(); i++) {
		cout << "strVec[" << i << "]=" << strVec[i] << endl;
	}
	return 0;
}