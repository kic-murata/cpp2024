#include <iostream>
#include <fstream>//�t�@�C���X�g���[��
#include <sstream>//������X�g���[��
#include <string>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;//�f�t�H���g�R���X�g���N�^
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp)
		, m_atk(atk), m_def(def) {};
	~Enemy() = default;//�f�t�H���g�f�X�g���N�^
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};


int main() {
	//�t�@�C���ǂݍ��ݗp�X�g���[���̐���
	ifstream ifs("enemy_list.csv");
	if (ifs.fail()) {//�t�@�C���I�[�v���Ɏ��s
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;		 //�G���[�R�[�h-1
	}
	vector<Enemy*> vEne{};//Enemy�N���X�̔z��
	vector<string> v{};//CSV�̊e���ڂ��i�[����z��
	//int j = 0;//�s�ԍ��Ǘ��pj
	string text;
	while (getline(ifs, text)) {//��s�ǂݍ����text��
		//vEne.resize(j + 1);//vEne�Ɉ�s���̗̈��ǉ�
		istringstream iss(text);//������X�g���[������
		while (getline(iss, text, ',')) {//�u,�v�ŕ���
			v.push_back(text);
		}
		//stoi: ������𐮐��l�ɕϊ�
		vEne.push_back(new Enemy(v[0], stoi(v[1])
			, stoi(v[2]), stoi(v[3])));
		v.clear();//�S�v�f���폜
		//j++;
	}
	ifs.close();
	//vEne.size(): �@�@�s�����擾�ł���
	//vEne[0].size():�@�񐔂��擾�ł���
	//for (int i = 0; i < vEne.size(); i++) {
	//	for (int j = 0; j < vEne[0].size(); j++) {
	//		cout << vEne[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	for (auto p : vEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	return 0;
}