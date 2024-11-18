#pragma once
#include "maze2d.h"
//using namespace std;

//class MapData {
//public:
//  vector<vector<int>> mapData{};
//  MapData() = default;
//  int getMapValue(int x, int y) { return mapData[y][x]; }
//  int getMapSize(int i) { return mapData[i].size(); }
//  int getMapSize() { return mapData.size(); }
//  void addMap(int j, int value) { mapData[j].push_back(value); }
//  void resizeMap() { mapData.resize(mapData.size() + 1); }
//  void setMapValue(int x, int y, int value) { mapData[y][x] = value; }
//};

class Map {
public:
  MapData mapdata;
  Map();
  void Load(string filename);
  void setTreasure();
  //void DrawMap(int playerX, int playerY);
  void DrawMap();
};

