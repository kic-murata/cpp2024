#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> intVec;
	vector<int> intVec2{ 99,98,97 };
	vector<string> strVec;
	if (intVec.empty()) {
		cout << "intVec‚Í‹ó‚Ì”z—ñ" << endl;
	}
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
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

	for (int i = 0; i < intVec.size(); i++) {
		cout << "intVec[" << i << "]=" << intVec[i] << endl;
	}
	for (int i = 0; i < strVec.size(); i++) {
		cout << "strVec[" << i << "]=" << strVec[i] << endl;
	}
	return 0;

}