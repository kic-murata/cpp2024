#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���I" << endl;
		return -1;
	}
	vector<string> vEne{};//�ꎟ���z��̐錾
	string text;
	getline(ifs, text);//��s����CSV����ǂݍ���
	istringstream iss(text);//������X�g���[���ɕϊ�
	while (getline(iss, text, ',')) {//������X�g���[����','�ŕ���
		vEne.push_back(text);//�����������ڂ�z��֊i�[
	}
	ifs.close();
	for (auto d : vEne) {//�͈�for�Ŕz��̑S�v�f��\��
		cout << d << endl;
	}
	return 0;
}