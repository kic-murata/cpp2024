#include "maze.h"
#include "player.h"
#include <iostream>
using namespace std;
Player::Player() : Pos(0, 0) {};
Player::Player(int x, int y) : Pos(x, y) {};
void Player::setX(int x) {
	Pos.x = x;
}
void Player::setY(int y) {
	Pos.y = y;
}
int Player::getX() {
	return Pos.x;
}
int Player::getY() {
	return Pos.y;
}
int Player::move(char key, MapData& mapdata) {
	int newPosX = Pos.x;//現在の座標をコピー
	int newPosY = Pos.y;
	switch (key) {
	case 'w':		//上移動
		newPosY--;
		break;
	case 'a':		//左移動
		newPosX--;
		break;
	case 's':		//下移動
		newPosY++;
		break;
	case 'd':		//右移動
		newPosX++;
		break;
	case '@':		//強制終了用
		exit(0);
	}
	if (newPosX >= 0 && newPosX < mapdata.getMapSize(0)
		&& newPosY >= 0 && newPosY < mapdata.getMapSize()) {
		//座標が壁に埋まっていないかどうかチェック
		if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
			Pos.x = newPosX;//自キャラの位置を更新
			Pos.y = newPosY;
			//座標が宝箱だった場合
			if (mapdata.getMapValue(newPosX, newPosY) == TREASURE) {
				return 99;
			}
		}
	}
	return 0;
}