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
void Map::DrawMap() {
	//x=0~最大列数、y=0～最大行数までループ
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			//配列の要素の値がWALL(1)なら#を表示
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			//配列の要素の値がROAD(0)なら.を表示
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl;
	}
}