#pragma once
#include "maze.h"
using namespace std;
//�\����Vector2
struct Vector2 {
	int x, y;//���L������x,y���W���Ǘ�����
	Vector2(int x, int y) :x(x), y(y) {};
};
class Player {
private:
	Vector2 Pos;	//�\����Vector2�^�ϐ�Pos
public:
	Player();             //�R���X�g���N�^�i�����Ȃ��j
	Player(int x, int y); //�R���X�g���N�^�i��������j
	void setX(int x);     //�Z�b�^�[
	void setY(int y);
	int getX();           //�Q�b�^�[
	int getY();
	//�}�b�v��ňړ��\���ǂ����𒲂ׂāA���L�������W���X�V����
	void move(char key, MapData& mapdata);
};