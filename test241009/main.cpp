#include <iostream>
#include <string>
#include <vector>
//#include "cxx-prettyprint/prettyprint.hpp"
using namespace std;

int main()
{
	vector<int> v1{ 10,9,8 }; //ฎ^ฎIz๑v1
	vector<string> v2; //ถ๑ฎIz๑v2
//	vector<vector<int>> v3(3, vector<int>(3)) {};
	vector<vector<int>> v3{ {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> v4(2, vector<int>(2));

	vector<vector<int>>::iterator itr3;
	itr3 = v3.begin();

	cout << itr3->at(0) << endl;//1
	cout << *(itr3->begin()) << endl;//1
	cout << *(itr3->begin() + 1) << endl;//2
	cout << itr3->at(1) << endl;//2
	cout << *(itr3->begin() + 2) << endl;//3
	cout << *((itr3 + 1)->begin()) << endl;//4
	cout << *((itr3 + 1)->begin() + 1) << endl;//5
	cout << (itr3 + 1)->at(1) << endl;//5
	cout << *((itr3 + 1)->begin() + 2) << endl;//6
	cout << *((itr3 + 2)->begin()) << endl;//7
	cout << *((itr3 + 2)->begin() + 1) << endl;//8
	cout << *((itr3 + 2)->begin() + 2) << endl;//9

	for (int i = 0; i < v3.size(); i++) {
		for (int j = 0; j < v3[0].size(); j++) {
			cout << v3[i][j] << " ";
		}
		cout << endl;
	}

	//prettyprintp
	//cout << v3 << endl;
	

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back("ABC");
	v2.push_back("DEF");

	v1.pop_back(); //๖ฬvfฬํ
	v1.emplace_back(4);

	cout << "v1ฬvf" << v1.size() << endl;

	vector<int>::iterator itr = v1.begin();
	cout << "Ce[^[๊" << *itr << endl;
	v1.insert(itr + 2, 20);
	itr = v1.begin();
	v1.erase(itr + 4);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}

	v2.pop_back(); //๖ฬvfฬํ
	v2.emplace_back("G");

	cout << "v2ฬvf" << v2.size() << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	return 0;
}