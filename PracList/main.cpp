#include <list>
#include <iostream>
using namespace std;
int main() {
	{ //li1�̖����ɒǉ����ĘA��������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto d : li2) {
			li1.push_back(d);
		}
		li1.sort();
		cout << "�����ɒǉ�:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2�̐擪�ɒǉ����ĘA��������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//���o�[�X�i�t�j�C�e���[�^���g����li1�̖���������o��
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}
		li2.sort();
		cout << "�擪�ɒǉ�:";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li1��li2��merge���ĘA��������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "merge�ŘA��:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	{	//li1��li2��insert���ĘA��������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.insert(li1.end(), li2.begin(), li2.end());
		cout << "insert�ŘA��:";
		li1.sort();
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	{	//li1��li2��splice���ĘA��������@
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.splice(li1.end(), li2);
		li1.sort(); 
		cout << "splice�ŘA��:";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << li2.size() << endl;
	}
	return 0;
}