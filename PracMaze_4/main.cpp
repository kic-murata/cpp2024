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
	//マップデータ上に宝物のデータを格納
	map.SetTreasure();
	//Playerクラスのインスタンス生成
	Player player;
	random_device rnd_dev{}; //乱数生成器
	mt19937 rand_engine(rnd_dev());//メルセンヌツイスター
	//分布生成器を使って、trXは2~(列数)-3、trYは2~(行数)に制限
	uniform_int_distribution<int> rnd_x(2, map.mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int> rnd_y(2, map.mapdata.getMapSize() - 3);
	while (true) {
		int px = rnd_x(rand_engine);//乱数を生成
		int py = rnd_y(rand_engine);
		//乱数で求めた座標が通路であった場合
		if (map.mapdata.getMapValue(px, py) == ROAD) {
			player.setX(px);
			player.setY(py);
			break;
		}
		//乱数で求めた座標が通路以外なら繰り返し乱数生成をする
	}

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
		//キー入力待ち（_getchは画面に入力したキーを表示しない）
		char input = _getch();
		//Playerクラスのmove関数の呼出し
		if (player.move(input, map.mapdata) == 99) {
			if (battle.Initialize() == 0) {
				cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
				return 0;
			}
			else
			{
				cout << "\033[31mゲームオーバー\033[m" << endl;
				return 0;
			}
		}
	}
	return 0;
}