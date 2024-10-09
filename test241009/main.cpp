#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1{ 10,9,8 }; //整数型動的配列v1
	vector<string> v2; //文字列動的配列v2

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