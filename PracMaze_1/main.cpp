#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include "battle.h"
#include <random>
#include <algorithm>
using namespace std;
int main() {
	Map map{};
	//CSV�t�@�C���̓ǂݍ��݂Ɣz��ւ̊i�[
	map.Load("2d_maze.csv"); 
	//���H��ɕ󕨂�ݒu
	map.SetTreasure();
	//Player�N���X�̃C���X�^���X�𐶐����ď����ʒu��^����
	Player player;
	//����������ƃ����Z���k�c�C�X�^�[�A���S���Y����ݒ�
	random_device rnd_dev{};
	mt19937 rand_engine(rnd_dev());
	//���z�������x,y���W�̒l�𐧌�����
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);//2~�ő��-3
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);//2~�ő�s��-3
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//�z���y�sx��ڂ̒l��ROAD(0)���ǂ������`�F�b�N
		if (map.mapdata.getMapValue(x, y) == ROAD) {
			player.setX(x);//���L�����̏����ʒu��ݒ�
			player.setY(y);
			break;//�������[�v�𔲂���
		}
	}
	//Battle�N���X�̃C���X�^���X�𐶐�
	Battle battle;
	//�R�}���h�v�����v�g�̉�ʂɕ\������Ă�����̂�����
	system("cls");
	while (true) {
		//�R�}���h�v�����v�g�̉�ʂ̍�����W�i0,0�j��\���ʒu�ɂ���
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
		);
		//�}�b�v��`��
		map.DrawMap(player.getX(), player.getY());
		//�L�[�{�[�h����ꕶ������
		char input = _getch();
		//Player�N���X��move�֐��𕶎��ƃ}�b�v�f�[�^�������Ƃ��Ď��s
		if (player.move(input, map.mapdata) == 99) {
			//�󕨂𔭌�������o�g���J�n
			if (battle.Initialize() == 0) {
				//�o�g���ɏ��������Ƃ�
				cout << "\033[33m����Q�b�g�I�Q�[���N���A\033[m" << endl;
				return 0;
			}
			else {
				//�o�g���ɔs�k�����Ƃ�
				cout << "\033[31m�Q�[���I�[�o�[�c\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}