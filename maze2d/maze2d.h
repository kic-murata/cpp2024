#pragma once
#include <vector>
using namespace std;

//22行×22列の二次元配列用領域を確保
vector<vector<int>> mapdata{};
//マップデータファイル名
static string m_filename{ "2d_maze22.csv" };

enum MapObj {
  ROAD,
  WALL,
  TREASURE = 4
};

class Vector2 {
public:
  int x;
  int y;
  Vector2() = default;
  Vector2(int x, int y) : x(x), y(y) {};
};
