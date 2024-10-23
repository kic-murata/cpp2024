#include <list>
#include <iostream>
using namespace std;
int main() {
	{	//li1の後ろにli2を連結
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto itr = li2.begin(); itr != li2.end(); itr++) {
			li1.push_back(*itr);
		}
		//for (auto d : li2) {
		//	li1.push_back(d);
		//}
		cout << "連結結果li1：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2の前にli1を連結
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//逆イテレータを使ったループ：rbeginがデータ末尾,rendが先頭
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}
		//li1.reverse();//データ列を逆順にする
		//for (auto d : li1) {
		//	li2.push_front(d);
		//}
		cout << "連結結果li2：";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//merge
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "連結結果merge：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
}