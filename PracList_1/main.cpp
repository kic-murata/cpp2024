#include<list>
#include<iostream>
using namespace std;
int main() {
	list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
	//li1�̖�����li2�̃f�[�^�����ɒǉ�������@
	//for (auto itr = li2.begin(); itr != li2.end(); itr++) {
	//	li1.push_back(*itr);
	//}
	for (auto d : li2) {
		li1.push_back(d);
	}
	li1.sort();//�����\�[�g
	cout << "�A�����ʁF ";
	for (auto d : li1) {
		cout << d << " ";
	}
	cout << endl;
}