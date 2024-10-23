#include <list>
#include <iostream>
using namespace std;
int main() {
	{	//li1�̖�����li2��A��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto it = li2.begin(); it != li2.end(); it++) {
			li1.push_back(*it);
		}
		//for (auto d : li2) {//�A���pfor
		//	li1.push_back(d);
		//}
		cout << "li1: ";
		for (auto d : li1) {//�\���pfor
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2�̐擪��li1��A��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//�t�C�e���[�^�@rbegin()�F�����@rend():�擪���O�̃C�e���[�^
		for (auto it = li1.rbegin(); it != li1.rend(); it++) {
			li2.push_front(*it);
		}
		//li1.reverse();	//�f�[�^����t���ɂ���@17 11 3 2
		//for (auto d : li1) {
		//	li2.push_front(d);
		//}
		cout << "li2: ";
		for (auto d : li2) {//�\���pfor
			cout << d << " ";
		}
		cout << endl;
	}
	{	//merge�ŘA��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "merge: ";
		for (auto d : li1) {//�\���pfor
			cout << d << " ";
		}
		cout << endl;
	}
	{	//insert�ŘA��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//insert(�}���ꏊ,�}���������f�[�^�̐擪,����)
		li1.insert(li1.end(), li2.begin(), li2.end());
		cout << "li2�̗v�f��:" << li2.size() << endl;
		cout << "insert: ";
		for (auto d : li1) {//�\���pfor
			cout << d << " ";
		}
		cout << endl;
	}
	{	//splice�ŘA��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//splice(�}���ꏊ,�}�����������X�g)
		li1.splice(li1.end(), li2);
		li1.sort();
		cout << "li2�̗v�f��:" << li2.size() << endl;
		cout << "splice: ";
		for (auto d : li1) {//�\���pfor
			cout << d << " ";
		}
		cout << endl;
	}
}