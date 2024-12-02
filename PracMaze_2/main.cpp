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
	Player player;	//Playerクラスのインスタンス生成
	Battle battle;	//Battleクラスのインスタンス生成
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
		//Playerクラスのmove関数の戻り値が99のときは宝物を発見
		if (player.move(input, map.mapdata) == 99) {
			//BattleクラスのInitialize関数の戻り値が0のとき戦闘に勝利
			if (battle.Initialize() == 0) {
				cout << "\033[33mお宝発見！ゲームクリア\033[m" << endl;
				exit(0);//exit関数はアプリケーションを強制的に終了
			}
			else {//戻り値が0以外のときは、戦闘に敗北の場合
				cout << "\033[31mゲームオーバー\033[m" << endl;
				exit(0);
			}
		}
	}
	return 0;
}