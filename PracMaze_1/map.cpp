#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

Map::Map() = default;               //デフォルトコンストラクタ
void Map::Load(string filename) {   //CSVファイルの読み込み
	ifstream ifs(filename);           //入力ファイルストリームの生成
	if (ifs.fail()) {                 //オープンに失敗したとき
		cout << "FileOpenError" << endl;//エラーメッセージ表示
		exit(-1);                       //エラーコード(-1)
	}
	string text;
	int j = 0;                         //二次元配列の行数を管理する変数
	while (getline(ifs, text)) {       //CSVから一行読み取り
		mapdata.resizeMap();             //二次元配列の行数を一行増やす
		istringstream iss(text);         //文字列ストリームに変換
		while (getline(iss, text, ',')) {//コンマ記号で分割
			mapdata.addMap(j, stoi(text)); //分割したものを二次元配列へ追加
		}
		j++;                             //行数を増やす
	}
	ifs.close();                       //ファイルを閉じる
}
void Map::DrawMap() {
	//y = 0　～　全行数-1　までループ
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		//x = 0　～　y行目の全列数-1　までループ
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			//マップデータの指定の座標の値がWALL(1)のとき
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			//マップデータの指定の座標の値がROAD(0)のとき
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl; //一行分表示(xのループが終了）したら改行
	}
}