#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{5, 8, 2};
	li.push_back(1);	//5 8 2 1
	li.push_back(2);	//5 8 2 1 2
	li.push_front(3);	//3 5 8 2 1 2
	auto itr = li.begin();//liの先頭イテレータ取得
	itr++;						//イテレータを１つ進める
	li.insert(itr, 4);//4を挿入 3 4 5 8 2 1 2
	li.sort();				//昇順ソート 1 2 2 3 4 5 8
	li.unique();			//重複データを削除 1 2 3 4 5 8
	li.remove(8);			//8を削除 1 2 3 4 5
	li.reverse();			//データ列を逆順 5 4 3 2 1
	//for (itr = li.begin(); itr != li.end(); itr++) {
	//	cout << *itr << " ";
	//}
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}