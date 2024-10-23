#include <iostream>
#include <string>
#include <iomanip>
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
	//c++17�ȍ~�łł���悤�ɂȂ������@
	//��������
	for (const auto& [key, value] : score) {
		cout << key << " " << value <<  endl;
	}
	//�����܂�
	score.emplace("Michael", 70);//emplace�̏ꍇ�Apair�͕s�v
	score.insert(pair("AAA",10));//�C�e���[�^�s�v�i����Ƀ\�[�g����邽�߁j
	for (auto itr = begin(score); itr != end(score); itr++)
	{
		cout << itr->first << "," << itr->second << endl;
	}

	for (auto it = score.begin(); it != score.end(); it++) {
		cout << "�L�[:" << it->first << " �l:" << it->second << endl;
	}
	for (auto p : score) {
		cout << "�L�[:" << p.first << " �l:" << p.second << endl;
	}

	string input;
	cin >> input;
	if (score.count(input)) {
		cout << score[input] << endl;
	}
	map<string, string> ai{ {"�R","��"},{"��","��"} };
	for (auto p : ai) {
		cout << p.first << " �Ƃ����� " << p.second << endl;
	}
	map<int, double> root{ {2,1.41421356},{3,1.7320504} };
	for (auto p : root) {
		cout << p.first << " �̕������� " << setprecision(6) << p.second << endl;
	}




	return 0;
}