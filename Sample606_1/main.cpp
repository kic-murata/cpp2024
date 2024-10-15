#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li;			//int値のlistを作成
	li.push_back(1);	//末尾に1を追加
	li.push_back(2);	//末尾に2を追加
	li.push_front(3);	//先頭に3を追加
	list<int>::iterator itr;	//listクラスのイテレータを宣言
	itr = li.begin();	//イテレータをlistの先頭に
	itr++;						//イテレータをひとつ進める
	li.insert(itr, 4);//イテレータの位置に4を挿入
	for (itr = li.begin(); itr != li.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}