#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//�t�@�C�����J��
	if (ifs.fail()) {//�t�@�C�����J���Ȃ��ꍇ�̏���
		cout << "�t�@�C���I�[�v���G���[�I" << endl;
		return -1; //�G���[�R�[�h-1��Ԃ�
	}
	cout << "�t�@�C�����I�[�v���I" << endl;
	string text;
	while (getline(ifs, text,',')) {//�t�@�C�������s�ǂݍ���
		cout << text << endl;
	}
	ifs.close(); //�J�����t�@�C���͕���
	return 0;
}