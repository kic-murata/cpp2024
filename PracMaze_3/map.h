#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapData�N���X�̃C���X�^���X�i�񎟌��z��j
	Map();	//�R���X�g���N�^
	void Load(string filename);//CSV�t�@�C���̓ǂݍ��݂Ɗi�[
	void DrawMap(int px, int py);//�}�b�v�`��
	void SetTreasure();//�󕨂�z�u����
};