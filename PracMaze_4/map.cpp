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
	//0行目から最大行数までループ
	for (int y = py - 2; y <= py + 2 ; y++) {
		//0列目から最大列数までループ
		for (int x = px - 2; x <= px + 2; x++) {
			//座標(px,py)の場所に自キャラ@を表示
			if (x == px && y == py) {
				cout << "@";
			}
			else {//自キャラを表示しないときは以下の処理
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";
				}
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";
				}
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";
				}
			}			
		}
		cout << endl;
	}
}
void Map::SetTreasure() {
	random_device rnd_dev{}; //乱数生成器
	mt19937 rand_engine(rnd_dev());//メルセンヌツイスター
	//分布生成器を使って、trXは2~(列数)-3、trYは2~(行数)に制限
	uniform_int_distribution<int> rnd_x(2, mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int> rnd_y(2, mapdata.getMapSize() - 3);
	while (true) {
		int trX = rnd_x(rand_engine);//乱数を生成
		int trY = rnd_y(rand_engine);
		//乱数で求めた座標が通路であった場合
		if (mapdata.getMapValue(trX, trY) == ROAD) {
			//マップデータ配列のその箇所をTREASURE(2)に書き換える
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
		//乱数で求めた座標が通路以外なら繰り返し乱数生成をする
	}
}