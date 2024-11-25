#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map;
	map.Load("2d_maze.csv");
	map.SetTreasure();
	system("cls");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
		COORD{ 0, 0 });
	map.DrawMap(2, 2);
	return 0;
}