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
	Map map{};
	//CSVファイルの読み込みと配列への格納
	map.Load("2d_maze.csv"); 
	//迷路上に宝物を設置
	map.SetTreasure();
	//Playerクラスのインスタンスを生成して初期位置を与える
	Player player;
	//乱数生成器とメルセンヌツイスターアルゴリズムを設定
	random_device rnd_dev{};
	mt19937 rand_engine(rnd_dev());
	//分布生成器でx,y座標の値を制限する
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);//2~最大列数-3
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);//2~最大行数-3
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//配列のy行x列目の値がROAD(0)かどうかをチェック
		if (map.mapdata.getMapValue(x, y) == ROAD) {
			player.setX(x);//自キャラの初期位置を設定
			player.setY(y);
			break;//無限ループを抜ける
		}
	}
	//Battleクラスのインスタンスを生成
	Battle battle;
	//コマンドプロンプトの画面に表示されているものを消去
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
		if (player.move(input, map.mapdata) == 99) {
			//宝物を発見したらバトル開始
			if (battle.Initialize() == 0) {
				//バトルに勝利したとき
				cout << "\033[33mお宝ゲット！ゲームクリア\033[m" << endl;
				return 0;
			}
			else {
				//バトルに敗北したとき
				cout << "\033[31mゲームオーバー…\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}