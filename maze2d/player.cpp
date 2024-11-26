#include "maze2d.h"
#include "player.h"
using namespace std;

Player::Player() : Pos(0, 0) {};
Player::Player(int x, int y) : Pos(x, y) {};
void Player::setX(int x) { Pos.x = x; }
void Player::setY(int y) { Pos.y = y; }
int Player::getX() { return Pos.x; }
int Player::getY() { return Pos.y; }
int Player::move(char key, MapData& mapdata) {
  int newPosX = Pos.x;
  int newPosY = Pos.y;
  switch (key) {
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
  case '@': // 強制終了
    exit(0);
  }

  if (newPosX >= 0 && newPosX < mapdata.getMapSize(0) && newPosY >= 0 && newPosY < mapdata.getMapSize()) //移動範囲チェック
  {
    if (mapdata.getMapValue(newPosX,newPosY) != WALL) {
      Pos.x = newPosX;   //移動可能ならプレイヤー位置を更新
      Pos.y = newPosY;

      if (mapdata.getMapValue(newPosX, newPosY) == TREASURE)   //プレイヤーの位置が宝箱のとき
      {
        return 99;
        cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
        exit(0);
      }
    }
  }
  return 0;
}

