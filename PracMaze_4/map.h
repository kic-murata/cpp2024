#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapData�N���X�̃C���X�^���X
	Map();
	void Load(string filename);  //CSV�t�@�C���̓ǂݍ��݂Ɣz��ւ̊i�[
	void DrawMap(int px, int py);//�R�}���h�v�����v�g�Ƀ}�b�v��\��
	void SetTreasure();          //�󕨂��}�b�v��ɔz�u����
};