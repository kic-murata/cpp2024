#pragma once
#include "maze.h"
using namespace std;
struct Vector2 {//�\����Vector2
	int x, y;     //�����o�ϐ��i���L�������W�j
	Vector2(int x, int y) :x(x), y(y) {};//�R���X�g���N�^
};
class Player {
private:
	Vector2 Pos;         //�\���̕ϐ�Pos
public:
	Player();            //�����Ȃ��R���X�g���N�^
	Player(int x, int y);//��������R���X�g���N�^
	void setX(int x);    //�Z�b�^�[
	void setY(int y);
	int getX();          //�Q�b�^�[
	int getY();
	//��������wasd�̂����ꂩ�A�������̓}�b�v�f�[�^�̂���񎟌��z��
	void move(char key, MapData& mapdata);

	
};