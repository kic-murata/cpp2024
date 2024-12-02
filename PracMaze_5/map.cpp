#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
Map::Map() = default;											//デフォルトコンストラクタ
void Map::Load(string filename) {					//CSVファイルの読み込み
	ifstream ifs(filename);									//入力ファイルストリームの生成
	if (ifs.fail()) {												//エラーが発生したときの処理
		cout << "ファイルオープンエラー" << endl;	//エラーメッセージの表示
		exit(-1);															//エラーコード-1で終了
	}
	string text;														//文字列型変数
	int j = 0;															//二次元配列の行数を管理する変数
	while (getline(ifs, text)) {						//CSVから一行ずつ読み込む
		mapdata.resizeMap();									//二次元配列に行を追加
		istringstream iss(text);							//文字列ストリームを生成
		while (getline(iss, text, ',')) {			//ストリームをコンマで分割
			mapdata.addMap(j, stoi(text));			//分割された項目を配列に格納
		}
		j++;																	//行数をカウントアップ
	}
	ifs.close();														//ファイルを閉じる
}
void Map::DrawMap(int px, int py) {
	//py-2行目からpy+2行目までループ
	for (int y = py - 2; y <= py + 2; y++) {
		//px-2列目からpx+2列目までループ
		for (int x = px - 2; x <= px + 2; x++) {
			//座標(x,y)が中心座標(px,py)のとき
			if (x == px && y == py) {
				cout << "@"; //自キャラを表示
			}
			//以下、中心座標以外のときの表示
			else {
				//配列要素の値がWALLの場合
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";
				}
				//配列要素の値がROADの場合
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";
				}
				//配列要素の値がTREASUREの場合
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";
				}
			}
		}
		//一行分表示が終わったら改行
		cout << endl;
	}
}
void Map::SetTreasure() {
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//分布生成器でx座標の乱数の範囲を2~(列数-3)に制限
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);
	//分布生成器でy座標の乱数の範囲を2~(行数-3)に制限
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);
	while (true) {
		//宝物のX,Y座標を乱数で求める
		int trX = rnd_x(rand_engine);
		int trY = rnd_y(rand_engine);
		//マップデータ配列のX,Y座標が通路（ROAD）だったら
		if (mapdata.getMapValue(trX, trY) == ROAD) {
			//その地点の配列データを宝物（TREASURE）に書き換える
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
	}
}