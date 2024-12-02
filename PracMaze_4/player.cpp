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
	int newPosX = Pos.x;
	int newPosY = Pos.y;
	switch (key) {
	case 'w'://wキーのときは上移動
		newPosY--;
		break;
	case 'a'://aキーのときは左移動
		newPosX--;
		break;
	case 's'://sキーのときは下移動
		newPosY++;
		break;
	case 'd'://dキーのときは右移動
		newPosX++;
		break;
	case '@'://@キーのときは強制終了
		exit(0);
	}
	if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
		Pos.x = newPosX;
		Pos.y = newPosY;
		if (mapdata.getMapValue(Pos.x, Pos.y) == TREASURE) {
			return 99;
			cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
			exit(0);
		}
	}
	return 0;
}
