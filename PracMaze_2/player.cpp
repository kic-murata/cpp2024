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
	int newPosX = Pos.x;//���݂̍��W���R�s�[
	int newPosY = Pos.y;
	switch (key) {
	case 'w':		//��ړ�
		newPosY--;
		break;
	case 'a':		//���ړ�
		newPosX--;
		break;
	case 's':		//���ړ�
		newPosY++;
		break;
	case 'd':		//�E�ړ�
		newPosX++;
		break;
	case '@':		//�����I���p
		exit(0);
	}
	if (newPosX >= 0 && newPosX < mapdata.getMapSize(0)
		&& newPosY >= 0 && newPosY < mapdata.getMapSize()) {
		//���W���ǂɖ��܂��Ă��Ȃ����ǂ����`�F�b�N
		if (mapdata.getMapValue(newPosX, newPosY) != WALL) {
			Pos.x = newPosX;//���L�����̈ʒu���X�V
			Pos.y = newPosY;
			//���W���󔠂������ꍇ
			if (mapdata.getMapValue(newPosX, newPosY) == TREASURE) {
				return 99;
			}
		}
	}
	return 0;
}