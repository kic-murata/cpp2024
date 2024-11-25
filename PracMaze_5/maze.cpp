#include "maze.h"
MapData::MapData() = default; //�f�t�H���g�R���X�g���N�^
int MapData::getMapValue(int x, int y) {//(x,y)�̃}�b�v�f�[�^��Ԃ�
	return mapData[y][x];
}
int MapData::getMapSize(int i) {//�w��s(i)�̗񐔂�Ԃ�
	return mapData[i].size();
}
int MapData::getMapSize() {//�z��̍s����Ԃ�
	return mapData.size();
}
void MapData::addMap(int j, int value) {//�w��s(j)��value��ǉ�����
	mapData[j].push_back(value);
}
void MapData::resizeMap() {//�񎟌��z��ɐV�����s��ǉ�
	mapData.resize(mapData.size() + 1);
}
void MapData::setMapValue(int x, int y, int value) {
	//(x,y)�̍��W�i�z���y�sx��̏ꏊ�j��value���i�[����
	mapData[y][x] = value;
}