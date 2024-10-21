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
	li.sort();					//�����\�[�g
	li.reverse();				//�t���ɕ��ёւ�
	li.unique();				//�d���폜
	li.remove(3);				//�l��3�̗v�f���폜
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}