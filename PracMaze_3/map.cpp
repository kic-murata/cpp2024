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
void Map::DrawMap() {
	//x=0~�ő�񐔁Ay=0�`�ő�s���܂Ń��[�v
	for (int y = 0; y < mapdata.getMapSize(); y++) {
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			//�z��̗v�f�̒l��WALL(1)�Ȃ�#��\��
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			//�z��̗v�f�̒l��ROAD(0)�Ȃ�.��\��
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl;
	}
}