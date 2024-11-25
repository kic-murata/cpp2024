#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map{};
	//CSVファイルの読み込みと配列への格納
	map.Load("2d_maze.csv"); 
	//コマンドプロンプトの画面に表示されているものを消去
	system("cls");
	//コマンドプロンプトの画面の左上座標（0,0）を表示位置にする
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
	);
	//マップを描画
	map.DrawMap();
	return 0;
}