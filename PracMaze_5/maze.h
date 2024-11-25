#pragma once
#include <vector>
using namespace std;

class MapData {
private:
	vector<vector<int>> mapData{};//�}�b�v�f�[�^�i�[�p�񎟌��z��
public:
	MapData();                    //�R���X�g���N�^
	int getMapValue(int x, int y);//�w����W(x,y)�̃}�b�v�f�[�^��Ԃ�
	int getMapSize(int i);        //�}�b�v�f�[�^�̗񐔂�Ԃ�
	int getMapSize();             //�@�@�@�V�@�@�̍s����Ԃ�
	void addMap(int j, int value);//�z��̎w��s(j)��value��ǉ�
	void resizeMap();             //�񎟌��z��ɐV�����s��ǉ�
	void setMapValue(int x, int y, int value);//�w����W��value���i�[
};

enum MapObj {
	ROAD,    //�ʘH:0
	WALL,    //�@��:1
	TREASURE //��:2
};