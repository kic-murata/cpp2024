#include "map.h"
#include "maze.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
Map::Map() = default;											//�f�t�H���g�R���X�g���N�^
void Map::Load(string filename) {					//CSV�t�@�C���̓ǂݍ���
	ifstream ifs(filename);									//���̓t�@�C���X�g���[���̐���
	if (ifs.fail()) {												//�G���[�����������Ƃ��̏���
		cout << "�t�@�C���I�[�v���G���[" << endl;	//�G���[���b�Z�[�W�̕\��
		exit(-1);															//�G���[�R�[�h-1�ŏI��
	}
	string text;														//������^�ϐ�
	int j = 0;															//�񎟌��z��̍s�����Ǘ�����ϐ�
	while (getline(ifs, text)) {						//CSV�����s���ǂݍ���
		mapdata.resizeMap();									//�񎟌��z��ɍs��ǉ�
		istringstream iss(text);							//������X�g���[���𐶐�
		while (getline(iss, text, ',')) {			//�X�g���[�����R���}�ŕ���
			mapdata.addMap(j, stoi(text));			//�������ꂽ���ڂ�z��Ɋi�[
		}
		j++;																	//�s�����J�E���g�A�b�v
	}
	ifs.close();														//�t�@�C�������
}
void Map::DrawMap(int px, int py) {
	//py-2�s�ڂ���py+2�s�ڂ܂Ń��[�v
	for (int y = py - 2; y <= py + 2; y++) {
		//px-2��ڂ���px+2��ڂ܂Ń��[�v
		for (int x = px - 2; x <= px + 2; x++) {
			//���W(x,y)�����S���W(px,py)�̂Ƃ�
			if (x == px && y == py) {
				cout << "@"; //���L������\��
			}
			//�ȉ��A���S���W�ȊO�̂Ƃ��̕\��
			else {
				//�z��v�f�̒l��WALL�̏ꍇ
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";
				}
				//�z��v�f�̒l��ROAD�̏ꍇ
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";
				}
				//�z��v�f�̒l��TREASURE�̏ꍇ
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";
				}
			}
		}
		//��s���\�����I���������s
		cout << endl;
	}
}
void Map::SetTreasure() {
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	//���z�������x���W�̗����͈̔͂�2~(��-3)�ɐ���
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);
	//���z�������y���W�̗����͈̔͂�2~(�s��-3)�ɐ���
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);
	while (true) {
		//�󕨂�X,Y���W�𗐐��ŋ��߂�
		int trX = rnd_x(rand_engine);
		int trY = rnd_y(rand_engine);
		//�}�b�v�f�[�^�z���X,Y���W���ʘH�iROAD�j��������
		if (mapdata.getMapValue(trX, trY) == ROAD) {
			//���̒n�_�̔z��f�[�^��󕨁iTREASURE�j�ɏ���������
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
	}
}