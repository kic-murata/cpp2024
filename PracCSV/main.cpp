#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	string filename = "weapon_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���!" << endl;
		return -1;
	}
	string text;
	getline(ifs, text);//�擪�s��ǂݔ�΂�
	while (getline(ifs, text)) {//�t�@�C�������܂ň�s���ǂݍ���
		istringstream iss(text);//������X�g���[���ɕϊ�
		while(getline(iss, text, ',')) {//������X�g���[����,�ŕ���
			cout << text << " ";
		}
		cout << endl;
	}
	ifs.close();
	return 0;
}