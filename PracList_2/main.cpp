#include<list>
#include<iostream>
using namespace std;
int main() {
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1の末尾にli2の要素を追加して連結
		for (auto d : li2) { //連結用ループ
			li1.push_back(d);
		}
		for (auto d : li1) { //表示用ループ
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li2の先頭にli1の末尾から順に追加
		for (auto itr = li1.rbegin()
			; itr != li1.rend(); itr++) { //連結用ループ
			li2.push_front(*itr);
		}
		for (auto d : li2) { //表示用ループ
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//merge関数を使った連結
		li1.merge(li2);
		for (auto d : li1) { //表示用ループ
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//insert関数を使った連結
		//第一引数：挿入する場所（イテレータ）
		//第二引数：挿入したいデータの先頭の場所
		//第三引数：　　　　〃　　　　末尾の場所
		li1.insert(li1.end(), li2.begin(), li2.end());
		for (auto d : li1) { //表示用ループ
			cout << d << " ";
		}
		cout << endl;
	}
}