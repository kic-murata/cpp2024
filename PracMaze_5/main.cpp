#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map;                //Mapクラスのインスタンス生成
	map.Load("2d_maze.csv");//迷路データの読み込みと配列への格納
	map.SetTreasure();      //宝物を生成
	system("cls");          //画面クリア
	//コマンドプロンプトのウインドウを指定して、表示位置を(0,0)へ設定
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
	map.DrawMap(10,5);          //マップをコマンドプロンプトへ描画
	return 0;
}