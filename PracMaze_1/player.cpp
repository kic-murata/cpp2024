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
	int newPosX = Pos.x; //x���W�̈ړ��\���ʒu
	int newPosY = Pos.y; //y���W�́@�@�V
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
	//�ړ��\���ʒu���|�l��ő�s���������͍ő�񐔂𒴂��Ă��Ȃ����̃`�F�b�N
	if (newPosX >= 0 && newPosX < mapdata.getMapSize(0)
		&& newPosY >= 0 && newPosY < mapdata.getMapSize()) {
		//�ړ��\���ʒu���ǂłȂ��ꍇ�i�܂�ʘH��󕨂̏ꍇ�j
		if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
			//���݈ʒu���ړ��\���ʒu�̒l�ɍX�V�i�ړ��������ƂɂȂ�j
			Pos.x = newPosX;
			Pos.y = newPosY;
			//�ړ���������ɕ󕨂��������Ƃ�
			if (mapdata.getMapValue(newPosX, newPosY) == TREASURE) {
				cout << "\033[33m���󔭌��I\033[m" << endl;
				exit(0);
			}
		}
	}
}