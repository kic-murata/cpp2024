#include<list>
#include<iostream>
using namespace std;
int main() {
	{	//li1�̖�����li2�̃f�[�^�����ɒǉ�������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
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
	{	//li2�̐擪��li1�̖����f�[�^���珇�ɒǉ�������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1.reverse();//li1���t���ɂ���
		//for (auto d : li1) {
		//	li2.push_front(d);
		//}
		//�t�C�e���[�^��p��������(rbegin)����擪(rend)�܂ł̃��[�v����
		for (auto it = li1.rbegin(); it != li1.rend(); it++) {
			li2.push_front(*it);
		}
		li2.sort();
		cout << "�A�����ʁF ";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	} 
	{	//merge
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);//li1��li2�𓝍�����i�����\�[�g���j
		cout << "�A�����ʁF ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
	{	//insert
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.insert(li1.end(), li2.begin(), li2.end());
		li1.sort();
		cout << "�A�����ʁF ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
	{	//splice
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.splice(li1.end(), li2);
		li1.sort();
		cout << "�A�����ʁF ";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << "li2�̗v�f��:" << li2.size() << endl;
	}
}