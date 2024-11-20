#pragma once
#include "maze2d.h"
//#include <vector>
using namespace std;

//class Vector2 {
//public:
struct Vector2 {
  int x;
  int y;
//  Vector2() = default;
  Vector2(int x, int y) : x(x), y(y) {};
};

class Player {
private:
  Vector2 Pos;
public:
  Player();
  Player(int x, int y);
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();
  void move(char key, MapData& mapdata);
};