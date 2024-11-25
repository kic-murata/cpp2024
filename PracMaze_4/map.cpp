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
void Map::DrawMap() {
	//0�s�ڂ���ő�s���܂Ń��[�v
	for (int y = 0; y < mapdata.getMapSize() ; y++) {
		//0��ڂ���ő�񐔂܂Ń��[�v
		for (int x = 0; x < mapdata.getMapSize(y); x++) {
			if (mapdata.getMapValue(x, y) == WALL) {
				cout << "#";
			}
			else if (mapdata.getMapValue(x, y) == ROAD) {
				cout << ".";
			}
		}
		cout << endl;
	}
}