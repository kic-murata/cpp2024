#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	//�L�[��������(string)�A�l������(int)��map�R���e�iscore�쐬
	map<string, int> score{};
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.insert(make_pair("John", 88));//score["John"]=88
	score.emplace("David", 70);					//score["David"]=70
	//score.erase("Mike"); //�L�["Mike"�ƒl76�̃y�A������

	auto itr = score.find("John");//score������John�̃C�e���[�^���擾
	//map�N���X�̃C�e���[�^��first�����o�̓L�[�Asecond�����o�͒l
	cout << itr->first << "�̓_��:" << itr->second << endl;

	cout << "Tom�̓_���F" << score["Tom"] << endl;
	cout << "Bob�̓_���F" << score["Bob"] << endl;
	if (score.count("Mike")) {
		cout << "Mike�̓_���F" << score["Mike"] << endl;
	}
	return 0;

}