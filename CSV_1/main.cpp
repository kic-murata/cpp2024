#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	//�t�@�C�����͗p�X�g���[��ifs�𐶐����ăI�[�v��
	ifstream ifs(filename);
	if (ifs.fail()) {//�G���[�`�F�b�N
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;     //�G���[�R�[�h�F-1
	}
	string text;
	getline(ifs, text);//�t�@�C�������s�ǂݍ���
	istringstream iss(text);//������X�g���[������
	getline(iss, text, ',');
	cout << text << endl;
	return 0;
}