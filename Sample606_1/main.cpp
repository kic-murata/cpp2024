#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li{ 5,8,2 };	//int�l��list���쐬
	li.push_back(1);	//������1��ǉ�
	li.push_back(2);	//������2��ǉ�
	li.push_front(3);	//�擪��3��ǉ�
	list<int>::iterator itr;	//list�N���X�̃C�e���[�^��錾
	itr = li.begin();	//�C�e���[�^��list�̐擪��
	itr++;						//�C�e���[�^���ЂƂi�߂�
	li.insert(itr, 4);//�C�e���[�^�̈ʒu��4��}��
	li.sort();				//�����\�[�g
	li.unique();			//�d���f�[�^�̍폜
	li.remove(3);			//�l��3�̃f�[�^�����X�g����폜
	li.reverse();			//�f�[�^����t���ɂ���
	for (auto d : li) {
		cout << d << " ";
	}
	cout << endl;
	return 0;
}