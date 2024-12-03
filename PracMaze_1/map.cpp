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
void Map::DrawMap(int px, int py) {
	//y = py-2�@�`�@py+2�@�܂Ń��[�v
	for (int y = py - 2; y <= py + 2 ; y++) {
		//x = px-2�@�`�@px+2�@�܂Ń��[�v
		for (int x = px - 2; x <= px + 2 ; x++) {
			//5x5�̒��S���W�܂�(px,py)�ɂȂ����Ƃ�
			if (x == px && y == py) {
				cout << "@";//���L������\��
			}
			//�ȉ��A���S���W�ȊO�̕\������
			else {
				//�}�b�v�f�[�^�̎w��̍��W�̒l��WALL(1)�̂Ƃ�
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";//�ԐF
				}
				//�}�b�v�f�[�^�̎w��̍��W�̒l��ROAD(0)�̂Ƃ�
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";//��
				}
				//�}�b�v�f�[�^�̎w��̍��W�̒l��TREASURE(2)�̂Ƃ�
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";//���F
				}
			}
		}
		cout << endl; //��s���\��(x�̃��[�v���I���j��������s
	}
}
void Map::SetTreasure() {
	//����������ƃ����Z���k�c�C�X�^�[�A���S���Y����ݒ�
	random_device rnd_dev{};
	mt19937 rand_engine(rnd_dev());
	//���z�������x,y���W�̒l�𐧌�����
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);//2~�ő��-3
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);//2~�ő�s��-3
	while (true) {
		int x = rnd_x(rand_engine);
		int y = rnd_y(rand_engine);
		//�z���y�sx��ڂ̒l��ROAD(0)���ǂ������`�F�b�N
		if (mapdata.getMapValue(x, y) == ROAD) {
			//ROAD(0)�������Ƃ��́A���̒n�_�̓��e��TREASURE(2)�ɏ�������
			mapdata.setMapValue(x, y, TREASURE);
			break;//�������[�v�𔲂���
		}
	}
}