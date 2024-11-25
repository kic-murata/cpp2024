#pragma once
#include <vector>
using namespace std;
class MapData{
private:
	//�}�b�v�f�[�^�i�[�pint�^�񎟌��z��
	vector<vector<int>> mapData{};
public:
	//�R���X�g���N�^
	MapData();
	//���W(x,y)�̃}�b�v�f�[�^�̒l���擾
	int getMapValue(int x, int y);
	//�w��s(i)�̔z��̗񐔂��擾
	int getMapSize(int i);
  //�z��̍s�����擾
	int getMapSize();
  //�w��s(j)��value��ǉ�
	void addMap(int j, int value);
	//�񎟌��z��̍s���𑝂₷
	void resizeMap();
	//���W(x,y)�̃}�b�v�f�[�^��value�ɍX�V
	void setMapValue(int x, int y, int value);
};
enum MapObj {
	ROAD,   //�ʘH:0
	WALL,   //�@��:1
	TREASURE//��:2
};
