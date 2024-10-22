#include "chara.h"
#include "player.h"
#include <iostream>
#include <vector>
using namespace std;

//vector�R���e�i�̗v�f�ɁAPlayer�N���X�̃C���X�^���X�̃A�h���X��
//�i�[���āA�p�����[�^��\������v���O�����B
//�\����́A�C���X�^���X�̏����Ɨv�f�̍폜���s���B
int main() {
	//                                  Name   Hp   Atk Def Sp
	vector<Player*> pPlayer{ new Player("�E��", 200, 80, 20, 80) };
	pPlayer.push_back(new Player("��m", 300, 90, 40, 10));
	pPlayer.push_back(new Player("���@�g��", 80, 10, 20, 200));
	pPlayer.push_back(new Player("�m��", 180, 60, 60, 120));
	cout << "���������L�����N�^��:" << pPlayer.size() << endl;
	for (int i = 0; i < pPlayer.size(); i++) {
		cout 
			<< " Name:" << pPlayer[i]->getName() << endl
			<< "   HP:" << pPlayer[i]->getHp() << endl
			<< "   SP:" << pPlayer[i]->getSp() << endl
			<< "  Atk:" << pPlayer[i]->getAtk() << endl
			<< "  Def:" << pPlayer[i]->getDef() << endl;
	}
	auto itr = pPlayer.begin();	//vector�̐擪�v�f�̃C�e���[�^�擾
	while ( itr != pPlayer.end() ) {
		cout << (*itr)->getName() << "�̃C���X�^���X�폜" << " > ";
		delete *itr;	//�C���X�^���X���g�p���Ă����A�h���X�̈�����
		cout << "�z��̗v�f���폜" << endl;
		itr = pPlayer.erase(itr);	//vector�̗v�f���폜
		if (pPlayer.empty()) {	//vector�̗v�f����ɂȂ��������`�F�b�N
			cout << "���ׂẴC���X�^���X����������" << endl;
		}
	}
	return 0;
}
