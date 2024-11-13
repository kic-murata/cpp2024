#pragma once
#include "maze2d.h"
#include <vector>

using namespace std;

class Player {
private:
  Vector2 Pos;
public:
  Player() : Pos(0,0) {};
  Player(int x, int y) : Pos(x, y) {};
  void setX(int x) { Pos.x = x; }
  void setY(int y) { Pos.y = y; }
  void move(int x, int y) {};
  int getX() { return Pos.x; }
  int getY() { return Pos.y; }
  void move(char key) {
    int newPosX = Pos.x;
    int newPosY = Pos.y;
    switch (key)
    {
    case 'w': // 上
      newPosY--;
      break;
    case 'a': // 左
      newPosX--;
      break;
    case 's': // 下
      newPosY++;
      break;
    case 'd': // 右
      newPosX++;
      break;
    case '@':
      exit(0);
    }

    if (newPosX >= 0 && newPosX < mapdata[0].size() && newPosY >= 0 && newPosY < mapdata.size()) //移動範囲チェック
    {
      if (mapdata[newPosY][newPosX] != WALL) {
        Pos.x = newPosX;   //移動可能ならプレイヤー位置を更新
        Pos.y = newPosY;

        if (mapdata[Pos.y][Pos.x] == TREASURE)   //プレイヤーの位置が宝箱のとき
        {
          cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
          exit(0);
        }
      }
    }
  }
};