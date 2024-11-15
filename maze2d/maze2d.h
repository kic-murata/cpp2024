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
  vector<vector<int>> mapData{};//二次元配列
  MapData();              //コンストラクタ
  int getMapValue(int x, int y);//指定座標のデータを返す
  int getMapSize(int i);  //列数を取得
  int getMapSize();       //行数を取得
  void addMap(int j, int value);//指定行(j)にvalueを追加
  void resizeMap();       //配列に新しい行を追加
  void setMapValue(int x, int y, int value);//指定座標にデータを格納
  //MapData() = default;
  //int getMapValue(int x, int y) { return mapData[y][x]; }
  //int getMapSize(int i) { return mapData[i].size(); }
  //int getMapSize() { return mapData.size(); }
  //void addMap(int j, int value) { mapData[j].push_back(value); }
  //void resizeMap() { mapData.resize(mapData.size() + 1); }
  //void setMapValue(int x, int y, int value) { mapData[y][x] = value; }
};