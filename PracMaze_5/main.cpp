#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include <random>
#include <algorithm>
#include "battle.h"
using namespace std;
int main() {
	Map map;                //Mapクラスのインスタンス生成
	map.Load("2d_maze.csv");//迷路データの読み込みと配列への格納
	map.SetTreasure();      //宝物を生成
	Player player;					//Playerクラスのインスタンス生成
	Battle battle;					//Battleクラスのインスタンス生成
	system("cls");          //画面クリア
	//乱数で自キャラの初期位置を設定する
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//分布生成器でx座標の乱数の範囲を2~(列数-3)に制限
	uniform_int_distribution<int>
		rnd_x(2, map.mapdata.getMapSize(0) - 3);
	//分布生成器でy座標の乱数の範囲を2~(行数-3)に制限
	uniform_int_distribution<int>
		rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true) {
		//宝物のX,Y座標を乱数で求める
		int px = rnd_x(rand_engine);
		int py = rnd_y(rand_engine);
		//マップデータ配列のX,Y座標が通路（ROAD）だったら
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
	}
	while (true) {
		//コマンドプロンプトのウインドウを指定して、表示位置を(0,0)へ設定
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		map.DrawMap(player.getX(), player.getY()); //マップをコマンドプロンプトへ描画
		char input = _getch();
		//移動したとき宝箱を見つけた（戻り値:99)
		if (player.move(input, map.mapdata) == 99) {
			//バトル開始
			if (battle.Initialize() == 0) {
				//戦闘に勝利したとき
				cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
				exit(0);//アプリケーションを終了（終了コード0）
			}
			else {
				//戦闘に敗北したとき
				cout << "\033[31mゲームオーバー\033[m" << endl;
				exit(0);
			}
		}
	}
	return 0;
}