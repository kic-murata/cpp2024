#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() :m_name(""), m_hp(0), m_atk(0), m_def(0) {};
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk), m_def(def) {};
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};

int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);//�t�@�C�����J��
	if (ifs.fail()) {//�t�@�C�����J���Ȃ��ꍇ�̏���
		cout << "�t�@�C���I�[�v���G���[�I" << endl;
		return -1; //�G���[�R�[�h-1��Ԃ�
	}
	cout << "�t�@�C�����I�[�v���I" << endl;
	vector<string> vEne{};//1�̂�Enemy�f�[�^�i�[�p�z��
	vector<Enemy*> pEne{};//Enemy�N���X�i�[�p�z��
	string text;
	while (getline(ifs, text)) {	//�t�@�C�����畡���s�ǂݍ���
		istringstream iss(text);//�ǂݍ��񂾕�������X�g���[���ϊ�
		while (getline(iss, text, ',')) {//������X�g���[����','�ŕ���
			vEne.push_back(text);//�e���ڂ�z��̊e�v�f�Ɋi�[
		}
		//stoi(������)�͕������int�l�ɕϊ�����֐�
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1]),
			stoi(vEne[2]), stoi(vEne[3])));
		vEne.clear();
	}
	ifs.close(); //�J�����t�@�C���͕���
	return 0;
}