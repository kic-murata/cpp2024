#include <list>
#include <iostream>
using namespace std;
int main() {
	list<int> li{ 5, 8, 2};
	li.push_back(1);
	li.push_back(2);
	li.push_front(3);
	auto itr = li.begin();
	itr++;
	li.insert(itr, 4);
	li.sort();
	li.unique();
	li.remove(3);
	for (auto d : li) {
		cout << d << " ";
	}
	//for(itr = li.begin(); itr != li.end();itr++){
	//	cout << *itr << " ";
	//}
	cout << endl;
	return 0;
}