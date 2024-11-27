#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map{};
	//CSVファイルの読み込みと配列への格納
	map.Load("2d_maze.csv"); 
	//マップデータ上に宝物のデータを格納
	map.SetTreasure();
	//コマンドプロンプトの画面に表示されているものを消去
	system("cls");
	//コマンドプロンプトの画面の左上座標（0,0）を表示位置にする
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
	);
	//マップを描画
	map.DrawMap(10,10);
	return 0;
}