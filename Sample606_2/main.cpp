#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{ 5, 8, 2};//listコンテナの作成[5 8 2]
	li.push_back(1);			//末尾に1追加[5 8 2 1]
	li.push_back(2);			//末尾に2追加[5 8 2 1 2]
	li.push_front(3);			//先頭に3追加[3 5 8 2 1 2]
	auto itr = li.begin();//先頭要素のイテレータを取得
	itr++;								//イテレータ＋１
	li.insert(itr, 4);		//イテレータの場所に4を挿入[3 4 5 8 2 1 2]
	li.sort();						//昇順ソートの実行[1 2 2 3 4 5 8]
	li.unique();					//重複データの削除[1 2 3 4 5 8]
	li.remove(3);					//値が3のデータを削除[1 2 4 5 8]
	li.reverse();					//データ列を逆転する[8 5 4 2 1]
	for (itr = li.begin(); itr != li.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;	
	return 0;
}