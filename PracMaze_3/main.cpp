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
	Map map;
	map.Load("2d_maze.csv");
	map.SetTreasure();
	Player player;
	system("cls");
	random_device rnd_dev{};
	mt19937 rnd_engine(rnd_dev());
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true) {
		int px = rnd_x(rnd_engine);
		int py = rnd_y(rnd_engine);
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
	}

	Battle battle;
	while(true){
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
		);
		map.DrawMap(player.getX(), player.getY());
		char input = _getch();
		//Player�N���X��move�֐��̖߂�l��99�̂Ƃ��i�󕨂𔭌������Ƃ��j
		if (player.move(input, map.mapdata) == 99) {
			//Battle�N���X��Initialize�֐��Ńo�g���J�n
			//Initialize�֐��̖߂�l��0�̂Ƃ��͏����A����ȊO�͔s�k
			if (battle.Initialize() == 0) {
				cout << "\033[33m���󔭌��I�I�Q�[���N���A\033[m" << endl;
				return 0;
			}
			else {
				cout << "\033[31m�Q�[���I�[�o�[�E�E�E\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}