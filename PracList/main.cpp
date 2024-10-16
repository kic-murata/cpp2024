#include <list>
#include <iostream>
using namespace std;
int main() {
	{ //li1の末尾に追加して連結する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto d : li2) {
			li1.push_back(d);
		}
		li1.sort();
		cout << "末尾に追加:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2の先頭に追加して連結する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//リバース（逆）イテレータを使ってli1の末尾から取り出す
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}
		li2.sort();
		cout << "先頭に追加:";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li1とli2をmergeして連結する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "mergeで連結:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	{	//li1とli2をinsertして連結する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.insert(li1.end(), li2.begin(), li2.end());
		cout << "insertで連結:";
		li1.sort();
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	{	//li1とli2をspliceして連結する方法
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.splice(li1.end(), li2);
		li1.sort(); 
		cout << "spliceで連結:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	return 0;
}