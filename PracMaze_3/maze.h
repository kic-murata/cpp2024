#pragma once
#include <vector>
using namespace std;

enum MapObj {
	ROAD,
	WALL,
	TREASURE
};

class MapData {
private:
	vector<vector<int>> mapData{};
public:
	MapData();
	int getMapValue(int x, int y);
	int getMapSize(int i);
	int getMapSize();
	void addMap(int j, int value);
	void resizeMap();
	void setMapValue(int x, int y, int value);
};