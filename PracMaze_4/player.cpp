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
	case 'w'://w�L�[�̂Ƃ��͏�ړ�
		newPosY--;
		break;
	case 'a'://a�L�[�̂Ƃ��͍��ړ�
		newPosX--;
		break;
	case 's'://s�L�[�̂Ƃ��͉��ړ�
		newPosY++;
		break;
	case 'd'://d�L�[�̂Ƃ��͉E�ړ�
		newPosX++;
		break;
	case '@'://@�L�[�̂Ƃ��͋����I��
		exit(0);
	}
	if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
		Pos.x = newPosX;
		Pos.y = newPosY;
		if (mapdata.getMapValue(Pos.x, Pos.y) == TREASURE) {
			return 99;
			cout << "\033[33m���󔭌��I�I�Q�[���N���A\033[m" << endl;
			exit(0);
		}
	}
	return 0;
}
