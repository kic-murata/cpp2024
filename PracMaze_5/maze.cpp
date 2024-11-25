#include "maze.h"
MapData::MapData() = default; //デフォルトコンストラクタ
int MapData::getMapValue(int x, int y) {//(x,y)のマップデータを返す
	return mapData[y][x];
}
int MapData::getMapSize(int i) {//指定行(i)の列数を返す
	return mapData[i].size();
}
int MapData::getMapSize() {//配列の行数を返す
	return mapData.size();
}
void MapData::addMap(int j, int value) {//指定行(j)にvalueを追加する
	mapData[j].push_back(value);
}
void MapData::resizeMap() {//二次元配列に新しい行を追加
	mapData.resize(mapData.size() + 1);
}
void MapData::setMapValue(int x, int y, int value) {
	//(x,y)の座標（配列のy行x列の場所）にvalueを格納する
	mapData[y][x] = value;
}