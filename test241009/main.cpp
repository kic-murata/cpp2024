#include <iostream>
#include <string>
#include <vector>
//#include "cxx-prettyprint/prettyprint.hpp"
using namespace std;

int main()
{
	vector<int> v1{ 10,9,8 }; //整数型動的配列v1
	vector<string> v2; //文字列動的配列v2
//	vector<vector<int>> v3(3, vector<int>(3)) {};
	vector<vector<int>> v3{ {1,2,3},{4,5,6},{7,8,9} };
	vector<vector<int>> v4(2, vector<int>(2));
	vector<vector<int>> v5{};


	cout << "v4" << endl;
	v4.at(0).at(0) = 99;
	v4[1].push_back(100);
	cout << v4[1][2] << endl;
	cout << "v3" << endl;
	cout << v3[1][0] << endl;
	cout << "v4の行数" << v4.size() << endl;
	cout << "v4[0]の列数" << v4[0].size() << endl;
	cout << "v4[1]の列数" << v4[1].size() << endl;
	cout << "v5の行数" << v5.size() << endl;
	v5.resize(1);
	v5[0].push_back(1);
	v5[0].push_back(2);
	cout << "v5の行数" << v5.size() << endl;
	v5.resize(2);
	cout << "v5の行数" << v5.size() << endl;
	cout << "v5[0]の列数" << v5[0].size() << endl;



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

	//prettyprint用
	//cout << v3 << endl;
	

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back("ABC");
	v2.push_back("DEF");

	v1.pop_back(); //末尾の要素の削除
	v1.emplace_back(4);

	cout << "v1の要素数" << v1.size() << endl;

	vector<int>::iterator itr = v1.begin();
	cout << "イテレーター場所" << *itr << endl;
	v1.insert(itr + 2, 20);
	itr = v1.begin();
	v1.erase(itr + 4);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}

	v2.pop_back(); //末尾の要素の削除
	v2.emplace_back("G");

	cout << "v2の要素数" << v2.size() << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	return 0;
}