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
	//�}�b�v�f�[�^��ɕ󕨂̃f�[�^���i�[
	map.SetTreasure();
	//Player�N���X�̃C���X�^���X����
	Player player;
	random_device rnd_dev{}; //����������
	mt19937 rand_engine(rnd_dev());//�����Z���k�c�C�X�^�[
	//���z��������g���āAtrX��2~(��)-3�AtrY��2~(�s��)�ɐ���
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true) {
		int px = rnd_x(rand_engine);//�����𐶐�
		int py = rnd_y(rand_engine);
		//�����ŋ��߂����W���ʘH�ł������ꍇ
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
		//�����ŋ��߂����W���ʘH�ȊO�Ȃ�J��Ԃ���������������
	}

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
		//�L�[���͑҂��i_getch�͉�ʂɓ��͂����L�[��\�����Ȃ��j
		char input = _getch();
		//Player�N���X��move�֐��̌ďo��
		if (player.move(input, map.mapdata) == 99) {
			if (battle.Initialize() == 0) {
				cout << "\033[33m���󔭌��I�I�Q�[���N���A\033[m" << endl;
				return 0;
			}
			else
			{
				cout << "\033[31m�Q�[���I�[�o�[\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}