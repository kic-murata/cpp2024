#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata; //MapData�N���X�̃C���X�^���X�i���H�f�[�^�j
	Map();                     //�R���X�g���N�^
	void Load(string filename);//CSV�t�@�C���̓ǂݍ��݁A�z��ւ̊i�[
	void DrawMap();            //�z������Ƃɉ�ʂɃ}�b�v��`��
};