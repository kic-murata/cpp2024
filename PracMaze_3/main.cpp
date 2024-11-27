#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
using namespace std;
int main() {
	Map map;
	map.Load("2d_maze.csv");
	map.SetTreasure();
	Player player(2, 2);
	system("cls");
	while(true){
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
		);
		char input = _getch();
		player.move(input, map.mapdata);
		map.DrawMap(player.getX(), player.getY());
	}
	return 0;
}