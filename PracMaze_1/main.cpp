#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
using namespace std;
int main() {
	Map map{};
	//CSVファイルの読み込みと配列への格納
	map.Load("2d_maze.csv"); 
	//迷路上に宝物を設置
	map.SetTreasure();
	//コマンドプロンプトの画面に表示されているものを消去
	Player player(2, 2);
	//Playerクラスのインスタンスを生成して初期位置を与える
	system("cls");
	while (true) {
		//コマンドプロンプトの画面の左上座標（0,0）を表示位置にする
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
		);
		//マップを描画
		map.DrawMap(player.getX(), player.getY());
		//キーボードから一文字入力
		char input = _getch();
		//Playerクラスのmove関数を文字とマップデータを引数として実行
		player.move(input, map.mapdata);
	}
	return 0;
}