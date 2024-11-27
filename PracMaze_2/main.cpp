#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <random>
#include <algorithm>
#include "map.h"
#include "player.h"
using namespace std;
int main() {
	Map map;
	map.Load("2d_maze.csv");
	map.SetTreasure();
	random_device rnd_dev{};
	mt19937 rnd_engine(rnd_dev());
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);
	Player player;
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
		player.move(input, map.mapdata);
	}
	return 0;
}