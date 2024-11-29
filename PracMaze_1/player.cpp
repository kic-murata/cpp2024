#include "player.h"
#include "maze.h"
#include <iostream>
using namespace std;
Player::Player() : Pos(0, 0) {};
Player::Player(int x, int y) :Pos(x, y) {};
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
void Player::move(char key, MapData& mapdata) {
	int newPosX = Pos.x; //x座標の移動予測位置
	int newPosY = Pos.y; //y座標の　　〃
	switch (key) {
	case 'w':
		newPosY--;
		break;
	case 'a':
		newPosX--;
		break;
	case 's':
		newPosY++;
		break;
	case 'd':
		newPosX++;
		break;
	case '@':
		exit(0);
	}
	//移動予測位置が－値や最大行数もしくは最大列数を超えていないかのチェック
	if (newPosX >= 0 && newPosX < mapdata.getMapSize(0)
		&& newPosY >= 0 && newPosY < mapdata.getMapSize()) {
		//移動予測位置が壁でない場合（つまり通路や宝物の場合）
		if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
			//現在位置を移動予測位置の値に更新（移動したことになる）
			Pos.x = newPosX;
			Pos.y = newPosY;
			//移動する方向に宝物があったとき
			if (mapdata.getMapValue(newPosX, newPosY) == TREASURE) {
				cout << "\033[33mお宝発見！\033[m" << endl;
				exit(0);
			}
		}
	}
}