#include "maze.h"
//�f�t�H���g�R���X�g���N�^
MapData::MapData() = default;
//���W(x,y)�܂�y�sx��̔z��v�f���擾
int MapData::getMapValue(int x, int y) {
	return mapData[y][x];
}
//i�s�ڂ̍ő�񐔂��擾
int MapData::getMapSize(int i) {
	return mapData[i].size();
}
//�z��S�̂̍ő�s�����擾
int MapData::getMapSize() {
	return mapData.size();
}
//�񎟌��z���j�s�ڂ�value��ǉ�
void MapData::addMap(int j, int value) {
	mapData[j].push_back(value);
}
//�񎟌��z��̍s����V�K�Ɉ�s�ǉ�
void MapData::resizeMap() {
	mapData.resize(mapData.size() + 1);
}
//���W(x,y)�܂�y�sx��ڂ�value�l���i�[
void MapData::setMapValue(int x, int y, int value) {
	mapData[y][x] = value;
}
