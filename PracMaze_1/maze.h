#pragma once
#include <vector>
using namespace std;

enum MapObj {
	ROAD,    //�ʘH�F0
	WALL,    //�ǁ@�F1
	TREASURE //�󕨁F2
};

class MapData {
private:
	//�}�b�v�f�[�^�i�[�p�̓񎟌��z��
	vector<vector<int>> mapData{};
public:
	//�R���X�g���N�^
	MapData();
	//�w�肵�����W(x,y)�̃f�[�^��Ԃ�
	int getMapValue(int x, int y);
	//�w��s�̗񐔂�Ԃ�
	int getMapSize(int i);
	//�z��̍ő�s����Ԃ�
	int getMapSize();
	//�w��s�Ƀf�[�^�ivalue�j��ǉ�����
	void addMap(int j, int value);
	//�񎟌��z��̍s����V�K�ň�s���₷
	void resizeMap();
	//�w�肵�����W(x,y)�Ƀf�[�^�ivalue�j���i�[
	void setMapValue(int x, int y, int value);
};