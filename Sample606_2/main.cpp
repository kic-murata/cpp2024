#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{ 5, 8, 2};//list�R���e�i�̍쐬[5 8 2]
	li.push_back(1);			//������1�ǉ�[5 8 2 1]
	li.push_back(2);			//������2�ǉ�[5 8 2 1 2]
	li.push_front(3);			//�擪��3�ǉ�[3 5 8 2 1 2]
	auto itr = li.begin();//�擪�v�f�̃C�e���[�^���擾
	itr++;								//�C�e���[�^�{�P
	li.insert(itr, 4);		//�C�e���[�^�̏ꏊ��4��}��[3 4 5 8 2 1 2]
	li.sort();						//�����\�[�g�̎��s[1 2 2 3 4 5 8]
	li.unique();					//�d���f�[�^�̍폜[1 2 3 4 5 8]
	li.remove(3);					//�l��3�̃f�[�^���폜[1 2 4 5 8]
	li.reverse();					//�f�[�^����t�]����[8 5 4 2 1]
	for (itr = li.begin(); itr != li.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;	
	return 0;
}