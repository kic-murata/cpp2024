#pragma once
#include "maze.h"
using namespace std;
//�\����Vector2�Ŏ��L������x,y���W���Ǘ�
struct Vector2 {
	int x, y;
	Vector2(int x, int y) :x(x), y(y) {};
};
class Player {
private:
	Vector2 Pos;//�\���̕ϐ�Pos
public:
	Player();            //�����Ȃ��R���X�g���N�^
	Player(int x, int y);//��������R���X�g���N�^
	void setX(int x);    //�Z�b�^�[
	void setY(int y);
	int getX();          //�Q�b�^�[
	int getY();
	//�ړ������������ֈړ��\�����`�F�b�N���č��W���X�V����
	int move(char key, MapData& mapdata);
};