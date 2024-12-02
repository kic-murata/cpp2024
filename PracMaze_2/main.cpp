#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>
#include <algorithm>
#include "map.h"
#include "player.h"
#include "battle.h"
using namespace std;
int main() {
	Map map;
	map.Load("2d_maze.csv");
	map.SetTreasure();
	random_device rnd_dev{};
	mt19937 rnd_engine(rnd_dev());
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);
	Player player;	//Player�N���X�̃C���X�^���X����
	Battle battle;	//Battle�N���X�̃C���X�^���X����
	while (true) {
		int px = rnd_x(rnd_engine);
		int py = rnd_y(rnd_engine);
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
	}
	system("cls");
	while (true) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
			COORD{ 0, 0 });
		map.DrawMap(player.getX(), player.getY());
		char input = _getch();
		//Player�N���X��move�֐��̖߂�l��99�̂Ƃ��͕󕨂𔭌�
		if (player.move(input, map.mapdata) == 99) {
			//Battle�N���X��Initialize�֐��̖߂�l��0�̂Ƃ��퓬�ɏ���
			if (battle.Initialize() == 0) {
				cout << "\033[33m���󔭌��I�Q�[���N���A\033[m" << endl;
				exit(0);//exit�֐��̓A�v���P�[�V�����������I�ɏI��
			}
			else {//�߂�l��0�ȊO�̂Ƃ��́A�퓬�ɔs�k�̏ꍇ
				cout << "\033[31m�Q�[���I�[�o�[\033[m" << endl;
				exit(0);
			}
		}
	}
	return 0;
}