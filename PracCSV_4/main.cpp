#include <iostream>	//cout endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
#include <vector>		//vector
#include <iomanip>  //setw
using namespace std;
//Weapon�N���X�̒�`�Ǝ���
class Weapon {
private://(string)���햼�A(int)�U���́A���i�A�d�ʂ��i�[
	string m_name;
	int m_atk, m_price, m_weight;
public://�R���X�g���N�^/�f�X�g���N�^/�Q�b�^�[
	Weapon() = default;
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk), m_price(price),
		m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};
int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "�G���[" << endl;
		return -1;
	}
	vector<string> vec{};  //CSV�f�[�^�̈ꎞ�ۑ��p�z��
	vector<Weapon*> vWpn{};//Weapon�N���X�p�̔z��
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);//������X�g���[���̐���
		while (getline(iss, text, ',')) {//�u,�v�ŕ���
			vec.push_back(text);//CSV�̊e���ڂ��i�[
		}
		//vec�z��̗v�f�������Ƃ���Weapon�N���X�̃R���X�g���N�^��
		//���s���A���̌��ʓ���ꂽ�C���X�^���X�̃A�h���X���i�[
		vWpn.push_back(new Weapon(vec[0],stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		vec.clear();//�ꎞ�I�ɕۑ����Ă����e��S�폜�i�v�f���O�j
	}
	ifs.close();
	//����ꗗ�̕\��
	for (int i = 0; i < vWpn.size(); i++) {
		//�ʂ��ԍ��ƕ��햼�i�������j��\��
		cout << i << ":" << left << setw(12) << vWpn[i]->getName();
		if (vWpn[i]->getPrice() < 0) {
			//�񔄕i�i�E�����j��\��
			cout << right << setw(9) << "�񔄕i" << endl;
		}
		else
		{
			//���퉿�i�i�E�����j��\��
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
	}
	//����w�����b�Z�[�W�̕\��
	cout << "�ǂ̕�����w�����܂����H��";
	//�L�[�{�[�h���琔�l�����
	int i;
	cin >> i;
	//���͂������l������̒ʂ��ԍ��͈͓̔��Ȃ̂����`�F�b�N
	if (i >= 0 && i < vWpn.size()) {
		//�񔄕i�̂Ƃ��̏���
		if (vWpn[i]->getPrice() < 0) {
			cout << "�񔄕i�̂��ߍw���ł��܂���" << endl;
		}
		else {//�w���\�ȕ���̂Ƃ��̏���
			cout << vWpn[i]->getName() << "���w������" << endl
				<< "�U���͂�" << vWpn[i]->getAtk() << "�A�b�v����" << endl
				<< "�d�ʂ�" << vWpn[i]->getWeight() << "������" << endl;
		}
	}
	else {//�ʂ��ԍ��͈̔͊O�̏���
		cout << "����ȕ���͂���܂���" << endl;
	}


	return 0;
}