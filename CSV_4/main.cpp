#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string filename = "enemy_list.txt";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���" << endl;
		return -1;//�G���[�R�[�h:-1
	}

	return 0;
}