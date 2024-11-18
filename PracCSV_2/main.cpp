#include <iostream>	//cout,endl
#include <fstream>	//ifstream
#include <sstream>	//istringstream
#include <string>		//getline
#include <vector>		//vector
#include <iomanip>	//setw
using namespace std;
class Weapon {
private:
	string m_name;
	int m_atk, m_price, m_weight;
public:
	Weapon() = default;
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk), m_price(price)
		, m_weight(weight) {};
	string getName() { return m_name; }	
	int getAtk()     { return m_atk; }
	int getPrice()   { return m_price; }
	int getWeight()  { return m_weight; }
	~Weapon() = default;
};

int main() {
	//�t�@�C�������w�肵�ē��͗p�t�@�C���X�g���[��ifs�𐶐�
	ifstream ifs("weapon_list.csv");
	//�t�@�C�����J�������ǂ����̃`�F�b�N
	if (ifs.fail()) { //�G���[���̏���
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;			//�G���[�R�[�h-1�ŏI��
	}
	//if(!ifs){ �G���[���̏��� }�����̏������ł�OK
	
	//�t�@�C�������s���ǂݍ���ŕ\�����J��Ԃ����s
	string text;
	vector<string> vec{};//�ꎞ�I��CSV�̊e���ڂ�ۑ�����z��
	vector<Weapon*> vWpn{};//Weapon�N���X�̔z��
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {//��s�ǂݎ����text��
		istringstream iss(text); //������X�g���[��iss����
		while (getline(iss, text, ',')) {//�R���}�ŕ���
			vec.push_back(text);//�����������ڂ�z��vec�Ɋi�[
		}
		//vec�̗v�f��Weapon�N���X�̃R���X�g���N�^�̈����ɂ���
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		vec.clear();//��s���̓��e������
	}
	ifs.close();
	//����ꗗ�̕\��
	for (int i = 0; i < vWpn.size(); i++) {
		//�ʂ��ԍ��̕\��
		cout << i << ":";
		//���햼�̕\��getName()
		cout << vWpn[i]->getName();
		//���i�̕\��getPrice() (���񔄕i�̏������K�v)
		if (vWpn[i]->getPrice() < 0) {
			cout << "\t" << right << setw(9)
				<< "�񔄕i" << endl;
		}
		else
		{
			cout << "\t" << right << setw(8)
				<< vWpn[i]->getPrice() << "G" << endl;
		}
	}
	//����w�����[�h
	cout << "�ǂ̕�����w�����܂����H>";
	int sel;    //�w�����镐��̔ԍ����i�[����ϐ�
	cin >> sel; //�L�[�{�[�h����ԍ������
	if (sel >= 0 && sel < vWpn.size()) {
		if (vWpn[sel]->getPrice() < 0) {
			cout << vWpn[sel]->getName() << "�͍w���ł��܂���"
				<< endl;
		}
		else {//�w���\�ȂƂ��̏���
			cout << vWpn[sel]->getName() << "���w�����܂���"
				<< endl << "�U���͂�" << vWpn[sel]->getAtk()
				<< "�A�b�v����" << endl << "�d�ʂ�"
				<< vWpn[sel]->getWeight() << "������" << endl;
		}
	}
	else
	{
		cout << "���̕���͑��݂��܂���" << endl;
	}
	return 0;
}