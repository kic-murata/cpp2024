#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include <random>
#include <algorithm>
#include "battle.h"
using namespace std;
int main() {
	Map map;                //Map�N���X�̃C���X�^���X����
	map.Load("2d_maze.csv");//���H�f�[�^�̓ǂݍ��݂Ɣz��ւ̊i�[
	map.SetTreasure();      //�󕨂𐶐�
	Player player;					//Player�N���X�̃C���X�^���X����
	Battle battle;					//Battle�N���X�̃C���X�^���X����
	system("cls");          //��ʃN���A
	//�����Ŏ��L�����̏����ʒu��ݒ肷��
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//���z�������x���W�̗����͈̔͂�2~(��-3)�ɐ���
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);
	//���z�������y���W�̗����͈̔͂�2~(�s��-3)�ɐ���
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true) {
		//�󕨂�X,Y���W�𗐐��ŋ��߂�
		int px = rnd_x(rand_engine);
		int py = rnd_y(rand_engine);
		//�}�b�v�f�[�^�z���X,Y���W���ʘH�iROAD�j��������
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
	}
	while (true) {
		//�R�}���h�v�����v�g�̃E�C���h�E���w�肵�āA�\���ʒu��(0,0)�֐ݒ�
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		map.DrawMap(player.getX(), player.getY()); //�}�b�v���R�}���h�v�����v�g�֕`��
		char input = _getch();
		//�ړ������Ƃ��󔠂��������i�߂�l:99)
		if (player.move(input, map.mapdata) == 99) {
			//�o�g���J�n
			if (battle.Initialize() == 0) {
				//�퓬�ɏ��������Ƃ�
				cout << "\033[33m���󔭌��I�I�Q�[���N���A\033[m" << endl;
				exit(0);//�A�v���P�[�V�������I���i�I���R�[�h0�j
			}
			else {
				//�퓬�ɔs�k�����Ƃ�
				cout << "\033[31m�Q�[���I�[�o�[\033[m" << endl;
				exit(0);
			}
		}
	}
	return 0;
}