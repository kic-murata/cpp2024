#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> li;			//int�l��list���쐬
	li.push_back(1);	//������1��ǉ�
	li.push_back(2);	//������2��ǉ�
	li.push_front(3);	//�擪��3��ǉ�
	list<int>::iterator itr;	//list�N���X�̃C�e���[�^��錾
	itr = li.begin();	//�C�e���[�^��list�̐擪��
	itr++;						//�C�e���[�^���ЂƂi�߂�
	li.insert(itr, 4);//�C�e���[�^�̈ʒu��4��}��
	for (itr = li.begin(); itr != li.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
	return 0;
}