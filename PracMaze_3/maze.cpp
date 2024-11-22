#include "maze.h"
//�R���X�g���N�^
MapData::MapData() = default;
//���W(x,y)�̗v�f�̒lvalue��Ԃ�
int MapData::getMapValue(int x, int y) {
	return mapData[y][x];
}
//�񎟌��z��mapData�̗񐔂�Ԃ�
int MapData::getMapSize(int i) {
	return mapData[i].size();
}
//�񎟌��z��mapData�̍s����Ԃ�
int MapData::getMapSize() {
	return mapData.size();
}
//�񎟌��z��mapData�̂��s�ڂɃf�[�^value��ǉ�
void MapData::addMap(int j, int value) {
	mapData[j].push_back(value);
}
//�񎟌��z��mapData�̍s������s���₷
void MapData::resizeMap() {
	mapData.resize(mapData.size() + 1);
}
//�񎟌��z��mapData��y�sx��ڂɃf�[�^value���i�[
void MapData::setMapValue(int x, int y, int value) {
	mapData[y][x] = value;
}