#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���" << endl;
		return -1;//�G���[�R�[�h:-1
	}
	string text;
	getline(ifs, text);//��s�Ԃ�ǂݎ����text�֊i�[
	istringstream iss(text);//������X�g���[���ɕϊ�
	while (getline(iss, text, ',')) {//�X�g���[����[,]�ŕ���
		cout << text << endl;
	}
	ifs.close();//�t�@�C�������
	return 0;
}