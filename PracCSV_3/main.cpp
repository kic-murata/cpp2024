#include <iostream>//cout, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
using namespace std;
int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "OpenError" << endl;
		return -1;
	}
	string text;
	getline(ifs, text);//��s�i���o���j�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		cout << text << endl;
	}
	ifs.close();
	return 0;
}