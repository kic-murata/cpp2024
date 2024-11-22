#include "maze.h"
//コンストラクタ
MapData::MapData() = default;
//座標(x,y)の要素の値valueを返す
int MapData::getMapValue(int x, int y) {
	return mapData[y][x];
}
//二次元配列mapDataの列数を返す
int MapData::getMapSize(int i) {
	return mapData[i].size();
}
//二次元配列mapDataの行数を返す
int MapData::getMapSize() {
	return mapData.size();
}
//二次元配列mapDataのｊ行目にデータvalueを追加
void MapData::addMap(int j, int value) {
	mapData[j].push_back(value);
}
//二次元配列mapDataの行数を一行増やす
void MapData::resizeMap() {
	mapData.resize(mapData.size() + 1);
}
//二次元配列mapDataのy行x列目にデータvalueを格納
void MapData::setMapValue(int x, int y, int value) {
	mapData[y][x] = value;
}