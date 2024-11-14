#include "maze2d.h"
using namespace std;

MapData::MapData() = default;
int MapData::getMapValue(int x, int y) { 
	return mapData[y][x]; 
}
int MapData::getMapSize(int i) { 
	return mapData[i].size(); 
}
int MapData::getMapSize() { 
	return mapData.size();
}
void MapData::addMap(int j, int value) { 
	mapData[j].push_back(value);
}
void MapData::resizeMap() { 
	mapData.resize(mapData.size() + 1);
}
void MapData::setMapValue(int x, int y, int value) { 
	mapData[y][x] = value;
}
