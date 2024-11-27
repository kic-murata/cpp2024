#include "map.h"	//Mapクラスの定義ファイル
#include "maze.h"//MapDataクラスの定義ファイル
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
Map::Map() = default;//デフォルトコンストラクタ
//CSVファイルからの読み込みと二次元配列への格納処理
void Map::Load(string filename) {
	ifstream ifs(filename);//入力ストリームの生成
	if (ifs.fail()) {//エラーが発生したとき
		cout << "FileOpenError" << endl;
		exit(-1);//エラーコード-1で強制終了
	}
	string text;
	int j = 0;//行数を管理する変数
	while (getline(ifs, text)) {//ファイルから一行読み込む
		mapdata.resizeMap();//二次元配列に一行ぶんの格納領域を作成
		istringstream iss(text);//文字列ストリームを生成
		while (getline(iss, text, ',')) {//文字列ストリームを,で分割
			mapdata.addMap(j, stoi(text));//分割した項目を整数にして配列へ格納
		}
		j++;//行数を増やす
	}
	ifs.close();//ファイルを閉じる
}
void Map::DrawMap(int px, int py) {
	//x=px-2~px+2、y=py-2～py+2までループ
	for (int y = py - 2; y <= py + 2; y++) {
		for (int x = px - 2; x <= px + 2 ; x++) {
			//座標(px,py)の地点に自キャラ@を表示
			if(x == px && y == py){
				cout << "@";
			}
			else {//自キャラ以外の表示処理
				//配列の要素の値がWALL(1)なら#を表示
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";//赤色で#を表示
				}
				//配列の要素の値がROAD(0)なら.を表示
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";//黒で.を表示
				}
				//配列の要素の値がTREASURE(2)なら$を表示
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";//黄色で$を表示
				}
			}

		}
		cout << endl;
	}
}
void Map::SetTreasure() {
	random_device rnd_dev{};//乱数生成器
	mt19937 rand_engine(rnd_dev());//メルセンヌツイスターを使用
	//分布生成器でX座標は2~(列数-3),Y座標は2~(行数-3)に制限する
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);
	while (true) {
		int trX = rnd_x(rand_engine);//宝箱のX座標を乱数で決定
		int trY = rnd_y(rand_engine);//宝箱のY座標を乱数で決定
		//宝箱を設置する座標がROAD(0)かどうかをチェック
		if (mapdata.getMapValue(trX, trY) == ROAD) {
			//マップデータ配列の座標(trX,trY)をTREASURE(2)に書き換え
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
	}
}