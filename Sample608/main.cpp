#include <iostream>
#include <string>
#include <map>
using namespace std;
int main() {
	map<string, int> score;
	score["Tom"] = 100;
	score["Bob"] = 80;
	score["Mike"] = 76;
	score.erase("Mike");
	score.insert(make_pair("John", 88));
	cout << "Tom�̓_����" << score["Tom"] << "�_" << endl;
	cout << "Bob�̓_����" << score["Bob"] << "�_" << endl;
	if (score.count("Mike") > 0) {
		cout << "Mike�̓_����" << score["Mike"] << "�_" << endl;
	}
	if (score.count("John")) {//John�̃L�[�����݂��Ă����1��Ԃ��i�Ȃ���0�j
		cout << "----" << endl;
		auto itr = score.find("John");//John�̃L�[�̃C�e���[�^��Ԃ�
		cout << itr->first << "�̓_����" << itr->second << "�_" << endl;
		cout << "----" << endl;
	}
	for (const auto& [text, i] : score) {
		cout << text << " " << i <<  endl;
	}
	score.emplace("Michael", 70);//emplace�̏ꍇ�Apair�͕s�v
	score.insert(pair("AAA",10));//�C�e���[�^�s�v�i����Ƀ\�[�g����邽�߁j
	for (auto itr = begin(score); itr != end(score); itr++)
	{
		cout << itr->first << "," << itr->second << endl;
	}
	return 0;
}