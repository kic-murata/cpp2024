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
		li1.sort();
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
		li2.sort();
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
		cout << ":li2の要素数：" << li2.size();
		cout << endl;
	}
	{	//insert
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//insertの引数
		//第1引数：挿入したい場所のイテレータ
		//第2引数：挿入するデータの先頭イテレータ
		//第3引数：　　　　〃　　の末尾イテレータ
		li1.insert(li1.end(), li2.begin(), li2.end());
		li1.sort();
		cout << "連結結果insert：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << ":li2の要素数：" << li2.size();
		cout << endl;
	}
	{	//splice
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//spliceの引数
		//第1引数：挿入したい場所のイテレータ
		//第2引数：挿入するリスト
		li1.splice(li1.end(), li2);
		li1.sort();
		cout << "連結結果splice：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << ":li2の要素数：" << li2.size();
		cout << endl;
	}
}