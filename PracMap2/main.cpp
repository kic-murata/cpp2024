#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"����","activity"},
		{"���͋C","atmosphere"},{"���t","blood"},
		{"��","environment"},{"���x","temperature"}};

	cout << dic.begin()->first << endl;
//	for (auto p : dic) {
	for(auto it = dic.begin(); it != dic.end(); it++){
		cout << "�L�[�F" << it->first << endl;
	}


	//��������
	random_device rand_dev{}; //������������쐬
	mt19937 rand_engine(rand_dev());//�A���S���Y���Ƀ����Z���k�c�C�X�^�[���g��
	uniform_int_distribution<int> dist(0, dic.size() - 1);  // 0�`map�̗v�f��-1 ���ϓ��Ȋm���œ��镪�z������

	//map�̐擪�̃C�e���[�^�擾
	auto it = dic.begin();
	//������next�֐����g���ăC�e���[�^���X�V
	it = next(it, dist(rand_engine));
	cout << it->first << "���p��ɒ����ƁH";
	string input;
	cin >> input;
	if (input == it->second) {
		cout << "�����I" << endl;
	}
	else {
		cout << "�s����" << endl;
	}

	map<int, map<string, int>> 
		tMap{ { 1, { {"abc", 3} } }, { 2, { {"abc", 1} } },
					{ 3, { {"def", 9} } }, { 4, { {"def", 7} } }
	};
	cout << tMap[1]["abc"] << endl;
	cout << tMap[2]["abc"] << endl;
	cout << tMap[3]["def"] << endl;
	cout << tMap[4]["def"] << endl;

	return 0;
}
