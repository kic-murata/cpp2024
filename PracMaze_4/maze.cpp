#include "maze.h"
//デフォルトコンストラクタ
MapData::MapData() = default;
//座標(x,y)つまりy行x列の配列要素を取得
int MapData::getMapValue(int x, int y) {
	return mapData[y][x];
}
//i行目の最大列数を取得
int MapData::getMapSize(int i) {
	return mapData[i].size();
}
//配列全体の最大行数を取得
int MapData::getMapSize() {
	return mapData.size();
}
//二次元配列のj行目にvalueを追加
void MapData::addMap(int j, int value) {
	mapData[j].push_back(value);
}
//二次元配列の行数を新規に一行追加
void MapData::resizeMap() {
	mapData.resize(mapData.size() + 1);
}
//座標(x,y)つまりy行x列目にvalue値を格納
void MapData::setMapValue(int x, int y, int value) {
	mapData[y][x] = value;
}
