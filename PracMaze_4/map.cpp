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
void Map::DrawMap() {
	//0行目から最大行数までループ
	for (int y = 0; y < mapdata.getMapSize() ; y++) {
		//0列目から最大列数までループ
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl;
	}
}