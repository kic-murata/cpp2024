#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score;//map�R���e�i�̃C���X�^���X����
	score["Tom"] = 100;//�L�[:Tom �l:100�̃y�A��score�ɒǉ�
	score["Bob"] = 80; //�L�[:Bob �l:80�̃y�A��score�ɒǉ�
	score["Mike"] = 76;//�L�[:Mike �l:76�̃y�A��score�ɒǉ�
	score.emplace("David", 90);//�L�[:David �l:90��score�ɑ}��
	score.insert({ "John", 70 });//�L�[:John �l:70��score�ɑ}��
	//�C�e���[�^���g����score�S�v�f�̕\��
	for (auto it = score.begin(); it != score.end(); it++) {
		//first�F�L�[(Key)�@second�F�l(Value)
		cout << it->first << ":" << it->second << endl;
	}
	////�͈�for���g�����\��
	//for (auto p : score) {
	//	cout << p.first << ":" << p.second << endl;
	//}
	score.erase("Mike");//�L�[:Mike�̃f�[�^��score����폜

	cout << "Tom�̓_���F" << score["Tom"] << endl;
	cout << "Bob�̓_���F" << score["Bob"] << endl;
	
	if (score.count("Mike")) {//Mike�̃L�[�̑��݂��`�F�b�N
		cout << "Mike�̓_���F" << score["Mike"] << endl;
	}
	auto it = score.find("David");//David�̃L�[�̏ꏊ���C�e���[�^�Ŏ擾
	cout << it->first << "�̓_���F" << it->second << endl;

	//C++17�ȍ~�Ή�
	//for (const auto& [key, value] : score) {
	//	cout << "key:" << key << endl
	//		<< "value:" << value << endl;
	//}

	return 0;
}