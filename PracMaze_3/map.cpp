#include "map.h"	//Map�N���X�̒�`�t�@�C��
#include "maze.h"//MapData�N���X�̒�`�t�@�C��
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
Map::Map() = default;//�f�t�H���g�R���X�g���N�^
//CSV�t�@�C������̓ǂݍ��݂Ɠ񎟌��z��ւ̊i�[����
void Map::Load(string filename) {
	ifstream ifs(filename);//���̓X�g���[���̐���
	if (ifs.fail()) {//�G���[�����������Ƃ�
		cout << "FileOpenError" << endl;
		exit(-1);//�G���[�R�[�h-1�ŋ����I��
	}
	string text;
	int j = 0;//�s�����Ǘ�����ϐ�
	while (getline(ifs, text)) {//�t�@�C�������s�ǂݍ���
		mapdata.resizeMap();//�񎟌��z��Ɉ�s�Ԃ�̊i�[�̈���쐬
		istringstream iss(text);//������X�g���[���𐶐�
		while (getline(iss, text, ',')) {//������X�g���[����,�ŕ���
			mapdata.addMap(j, stoi(text));//�����������ڂ𐮐��ɂ��Ĕz��֊i�[
		}
		j++;//�s���𑝂₷
	}
	ifs.close();//�t�@�C�������
}
void Map::DrawMap(int px, int py) {
	//x=px-2~px+2�Ay=py-2�`py+2�܂Ń��[�v
	for (int y = py - 2; y <= py + 2; y++) {
		for (int x = px - 2; x <= px + 2 ; x++) {
			//���W(px,py)�̒n�_�Ɏ��L����@��\��
			if(x == px && y == py){
				cout << "@";
			}
			else {//���L�����ȊO�̕\������
				//�z��̗v�f�̒l��WALL(1)�Ȃ�#��\��
				if (mapdata.getMapValue(x, y) == WALL) {
					cout << "\033[31m#\033[m";//�ԐF��#��\��
				}
				//�z��̗v�f�̒l��ROAD(0)�Ȃ�.��\��
				else if (mapdata.getMapValue(x, y) == ROAD) {
					cout << "\033[30m.\033[m";//����.��\��
				}
				//�z��̗v�f�̒l��TREASURE(2)�Ȃ�$��\��
				else if (mapdata.getMapValue(x, y) == TREASURE) {
					cout << "\033[33m$\033[m";//���F��$��\��
				}
			}

		}
		cout << endl;
	}
}
void Map::SetTreasure() {
	random_device rnd_dev{};//����������
	mt19937 rand_engine(rnd_dev());//�����Z���k�c�C�X�^�[���g�p
	//���z�������X���W��2~(��-3),Y���W��2~(�s��-3)�ɐ�������
	uniform_int_distribution<int>
		rnd_x(2, mapdata.getMapSize(0) - 3);
	uniform_int_distribution<int>
		rnd_y(2, mapdata.getMapSize() - 3);
	while (true) {
		int trX = rnd_x(rand_engine);//�󔠂�X���W�𗐐��Ō���
		int trY = rnd_y(rand_engine);//�󔠂�Y���W�𗐐��Ō���
		//�󔠂�ݒu������W��ROAD(0)���ǂ������`�F�b�N
		if (mapdata.getMapValue(trX, trY) == ROAD) {
			//�}�b�v�f�[�^�z��̍��W(trX,trY)��TREASURE(2)�ɏ�������
			mapdata.setMapValue(trX, trY, TREASURE);
			break;
		}
	}
}