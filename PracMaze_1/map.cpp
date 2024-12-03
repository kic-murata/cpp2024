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
void Map::DrawMap(int px, int py) {
	//y = py-2　～　py+2　までループ
	for (int y = py - 2; y <= py + 2 ; y++) {
		//x = px-2　～　px+2　までループ
		for (int x = px - 2; x <= px + 2 ; x++) {
			//5x5の中心座標つまり(px,py)になったとき
			if (x == px && y == py) {
				cout << "@";//自キャラを表示
			}
			//以下、中心座標以外の表示処理
			else {
				//マップデータの指定の座標の値がWALL(1)のとき
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";//赤色
				}
				//マップデータの指定の座標の値がROAD(0)のとき
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";//黒
				}
				//マップデータの指定の座標の値がTREASURE(2)のとき
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";//黄色
				}
			}
		}
		cout << endl; //一行分表示(xのループが終了）したら改行
	}
}
void Map::SetTreasure() {
	//乱数生成器とメルセンヌツイスターアルゴリズムを設定
	random_device rnd_dev{};
	mt19937 rand_engine(rnd_dev());
	//分布生成器でx,y座標の値を制限する
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);//2~最大列数-3
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);//2~最大行数-3
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//配列のy行x列目の値がROAD(0)かどうかをチェック
		if (mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)だったときは、その地点の内容をTREASURE(2)に書き換え
			mapdata.setMapValue(x, y, TREASURE);
			break;//無限ループを抜ける
		}
	}
}