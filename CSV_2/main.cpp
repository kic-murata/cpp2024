#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//�t�@�C�����J��
	if (ifs.fail()) {//�t�@�C�����J���Ȃ��ꍇ�̏���
		cout << "�t�@�C���I�[�v���G���[�I" << endl;
		return -1; //�G���[�R�[�h-1��Ԃ�
	}
	cout << "�t�@�C�����I�[�v���I" << endl;
	vector<vector<string>> vEne{};//Enemy�f�[�^�i�[�p�z��
	string text;
	int j = 0;//�s�ԍ��Ǘ��p�ϐ�
	while (getline(ifs, text)) {	//�t�@�C�����畡���s�ǂݍ���
		istringstream iss(text);//�ǂݍ��񂾕�������X�g���[���ϊ�
		vEne.resize(j+1); //vEne[j]�̗̈�����
		while (getline(iss, text, ',')) {//������X�g���[����','�ŕ���
			vEne[j].push_back(text);//�e���ڂ�z��̊e�v�f�Ɋi�[
		}
		for (auto d : vEne[j]) {//�͈�for��vEne�̊e�v�f��d�ɑ��
			cout << d << endl;
		}
		j++;
	}
	ifs.close(); //�J�����t�@�C���͕���
	return 0;
}