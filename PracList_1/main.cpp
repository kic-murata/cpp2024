#include<list>
#include<iostream>
using namespace std;
int main() {
	{	//li1の末尾にli2のデータを順に追加する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//for (auto itr = li2.begin(); itr != li2.end(); itr++) {
		//	li1.push_back(*itr);
		//}
		for (auto d : li2) {
			li1.push_back(d);
		}
		li1.sort();//昇順ソート
		cout << "連結結果： ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2の先頭にli1の末尾データから順に追加する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1.reverse();//li1を逆順にする
		//for (auto d : li1) {
		//	li2.push_front(d);
		//}
		//逆イテレータを用いた末尾(rbegin)から先頭(rend)までのループ処理
		for (auto it = li1.rbegin(); it != li1.rend(); it++) {
			li2.push_front(*it);
		}
		li2.sort();
		cout << "連結結果： ";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	} 
	{	//merge
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);//li1にli2を統合する（昇順ソート込）
		cout << "連結結果： ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
	{	//insert
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.insert(li1.end(), li2.begin(), li2.end());
		li1.sort();
		cout << "連結結果： ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
	{	//splice
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.splice(li1.end(), li2);
		li1.sort();
		cout << "連結結果： ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2の要素数:" << li2.size() << endl;
	}
}