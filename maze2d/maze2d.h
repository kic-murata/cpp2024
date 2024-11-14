#pragma once
#include <vector>
#include <iostream>
using namespace std;

enum MapObj {
  ROAD,
  WALL,
  TREASURE
};

class Vector2 {
public:
  int x;
  int y;
  Vector2() = default;
  Vector2(int x, int y) : x(x), y(y) {};
};

class MapData {
public:
  vector<vector<int>> mapData{};
  MapData();
  int getMapValue(int x, int y);
  int getMapSize(int i);
  int getMapSize();
  void addMap(int j, int value);
  void resizeMap();
  void setMapValue(int x, int y, int value);
  //MapData() = default;
  //int getMapValue(int x, int y) { return mapData[y][x]; }
  //int getMapSize(int i) { return mapData[i].size(); }
  //int getMapSize() { return mapData.size(); }
  //void addMap(int j, int value) { mapData[j].push_back(value); }
  //void resizeMap() { mapData.resize(mapData.size() + 1); }
  //void setMapValue(int x, int y, int value) { mapData[y][x] = value; }
};