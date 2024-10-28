#include <list>
#include <iostream>
using namespace std;
int main() {
	{ //パターンA
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto d : li2) {//li1の末尾にli2の内容を連結
			li1.push_back(d);
		}
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //パターンB
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1.reverse();//li1:17 11 3 2
		//for (auto d : li1) {//li2の先頭にli1の内容を連結
		//	li2.push_front(d);
		//}
		//li1の逆イテレータを使った方法
		// rbegin()はデータ末尾 rend()はデータ先頭
		for (auto it = li1.rbegin(); it != li1.rend(); it++) {
			li2.push_front(*it);
		}
		cout << "連結結果：";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //パターンC（merge)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //パターンC（insert)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//第1引数：挿入される場所のイテレータ
		//第2引数：挿入するデータの先頭のイテレータ
		//第3引数：挿入するデータの末尾のイテレータ
		li1.insert(li1.end(),li2.begin(),li2.end());
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //パターンC（splice)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//第1引数：挿入される場所のイテレータ
		//第2引数：挿入するリスト
		li1.splice(li1.end(), li2);
		cout << "連結結果：";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
}