#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapData�N���X�̃C���X�^���X
	Map();          //�R���X�g���N�^
	void Load(string filename);//CSV�t�@�C���̓ǂݍ��݂Ɣz��ւ̊i�[
	void DrawMap(int px, int py); //�}�b�v�f�[�^�̉�ʕ\��
	void SetTreasure();//�󕨂̏ꏊ�𗐐��Ō���
};