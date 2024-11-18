#include <iostream>	//cout endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
using namespace std;
int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "�G���[" << endl;
		return -1;
	}
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);//������X�g���[���̐���
		while (getline(iss, text, ',')) {//�u,�v�ŕ���
			cout << text << " ";
		}
		cout << endl;
	}
	ifs.close();
	return 0;
}