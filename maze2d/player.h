#pragma once
#include "maze2d.h"
//#include <vector>
using namespace std;

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
  void move(char key);
};