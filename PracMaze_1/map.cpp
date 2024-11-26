#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

Map::Map() = default;               //�f�t�H���g�R���X�g���N�^
void Map::Load(string filename) {   //CSV�t�@�C���̓ǂݍ���
	ifstream ifs(filename);           //���̓t�@�C���X�g���[���̐���
	if (ifs.fail()) {                 //�I�[�v���Ɏ��s�����Ƃ�
		cout << "FileOpenError" << endl;//�G���[���b�Z�[�W�\��
		exit(-1);                       //�G���[�R�[�h(-1)
	}
	string text;
	int j = 0;                         //�񎟌��z��̍s�����Ǘ�����ϐ�
	while (getline(ifs, text)) {       //CSV�����s�ǂݎ��
		mapdata.resizeMap();             //�񎟌��z��̍s������s���₷
		istringstream iss(text);         //������X�g���[���ɕϊ�
		while (getline(iss, text, ',')) {//�R���}�L���ŕ���
			mapdata.addMap(j, stoi(text)); //�����������̂�񎟌��z��֒ǉ�
		}
		j++;                             //�s���𑝂₷
	}
	ifs.close();                       //�t�@�C�������
}
void Map::DrawMap() {
	//y = 0�@�`�@�S�s��-1�@�܂Ń��[�v
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		//x = 0�@�`�@y�s�ڂ̑S��-1�@�܂Ń��[�v
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			//�}�b�v�f�[�^�̎w��̍��W�̒l��WALL(1)�̂Ƃ�
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			//�}�b�v�f�[�^�̎w��̍��W�̒l��ROAD(0)�̂Ƃ�
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl; //��s���\��(x�̃��[�v���I���j��������s
	}
}