#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> intVec;
	vector<string> strVec;
	intVec.push_back(1);
	intVec.push_back(2);
	intVec.push_back(3);
	strVec.push_back("ABC");
	strVec.push_back("DEF");
	for (const auto& v : strVec) {
		cout << v << endl;
	}
	intVec.pop_back();
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