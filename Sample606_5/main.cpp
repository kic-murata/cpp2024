#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{5, 8, 2};
	li.push_back(1);	//5 8 2 1
	li.push_back(2);	//5 8 2 1 2
	li.push_front(3);	//3 5 8 2 1 2
	auto itr = li.begin();//li�̐擪�C�e���[�^�擾
	itr++;						//�C�e���[�^���P�i�߂�
	li.insert(itr, 4);//4��}�� 3 4 5 8 2 1 2
	li.sort();				//�����\�[�g 1 2 2 3 4 5 8
	li.unique();			//�d���f�[�^���폜 1 2 3 4 5 8
	li.remove(8);			//8���폜 1 2 3 4 5
	li.reverse();			//�f�[�^����t�� 5 4 3 2 1
	//for (itr = li.begin(); itr != li.end(); itr++) {
	//	cout << *itr << " ";
	//}
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}