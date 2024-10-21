#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{ 5, 8, 2};
	li.push_back(1);		//5 8 2 1
	li.push_back(2);		//5 8 2 1 2
	li.push_front(3);		//3 5 8 2 1 2
	auto itr = li.begin();
	li.insert(++itr, 4);//3 4 5 8 2 1 2
	li.sort();					//昇順ソート
	li.reverse();				//逆順に並び替え
	li.unique();				//重複削除
	li.remove(3);				//値が3の要素を削除
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}