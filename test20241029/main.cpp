#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
	string line;
	getline(cin, line);
	cout << "Hello " << line << "!" << endl;
	return 0;
}
/*
�W�����͂�����͂���镶������i�[����string�^�ϐ�line��錾�B
getline�֐��ɂ��A�W�����͂���line�֕�������i�[�B
cout�ɂ��A"Hello"�̌�ɁAline�Ɋi�[���ꂽ�������"!"��t�����ĕ\���B
*/