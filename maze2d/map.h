#pragma once
#include "maze2d.h"
using namespace std;
class Map {
public:
  Map();
  void Load(string filename);
  void setTreasure();
  void DrawMap(int playerX, int playerY);
};

