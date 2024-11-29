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
		//Playerクラスのmove関数の戻り値が99のとき（宝物を発見したとき）
		if (player.move(input, map.mapdata) == 99) {
			//BattleクラスのInitialize関数でバトル開始
			//Initialize関数の戻り値が0のときは勝利、それ以外は敗北
			if (battle.Initialize() == 0) {
				cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
				return 0;
			}
			else {
				cout << "\033[31mゲームオーバー・・・\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}