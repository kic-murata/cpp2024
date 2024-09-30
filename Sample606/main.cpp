#include <list>
#include <iostream>
using namespace std;

int main() {
	list<int> li{10,5,2};
	li.push_back(1);
	li.push_back(2);
	li.emplace_front(3);
	cout << "size:" << li.size() << endl;
	auto itr = li.begin();
	itr++;
	li.insert(itr, 4);
	cout << "size:" << li.size() << endl;
	//for (itr = li.begin(); itr != li.end(); itr++) {
	li.sort();
	li.unique();
	for(auto itr: li){
		cout << itr << " ";
	}
	cout << endl;
	li.erase(li.begin());
	cout << "size:" << li.size() << endl;
	li.remove(4);
	cout << "size:" << li.size() << endl;
	for (auto itr : li) {
		cout << itr << " ";
	}
	cout << endl;
	return 0;
}