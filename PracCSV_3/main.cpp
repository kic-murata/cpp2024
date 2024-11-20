#include <iostream>//cout, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
#include <vector>  //vector
#include <iomanip> //setw
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
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "OpenError" << endl;
		return -1;
	}
	vector<string> v{};//CSV�̊e���ڂ�ۑ�����z��
	vector<Weapon*> vWpn{};//Weapon�N���X�p�̔z��
	string text;
	getline(ifs, text);//��s�i���o���j�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			v.push_back(text);//CSV�̊e���ڂ�v�ɒǉ�
		}
		//CSV�̊e�v�f��Weapon�N���X�̃R���X�g���N�^�̈����ɂ���B
		//�������ꂽ�C���X�^���X�̃A�h���X��vWpn�Ɋi�[����B
		vWpn.push_back(new Weapon(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//�z��v�̗v�f��S�폜
	}
	ifs.close();
	//����ꗗ�̕\��
	for (int i = 0; i < vWpn.size(); i++) {
		//�ʂ��ԍ��F���햼�@�̕\��
		cout << i << ":"
			<< left << setw(12) << vWpn[i]->getName();
		//���i�@�̕\���i���i�����̐��Ȃ�񔄕i�j
		if (vWpn[i]->getPrice() < 0) {
			cout << right << setw(11) << "�񔄕i" << endl;
		} else
		{ 
			cout << right << setw(10) 
				<< vWpn[i]->getPrice() << "G" << endl;
		}
	}
	cout << "�ǂ̕�����w�����܂����H��";
	int no;
	cin >> no; //�L�[�{�[�h����̓��͂�no�Ɋi�[
	//no�̗L���͈̓`�F�b�N
	if (no >= 0 && no < vWpn.size()) {
		if (vWpn[no]->getPrice() < 0) {
			cout << "�񔄕i�̂��ߍw���ł��܂���" << endl;
		}
		else
		{
			cout << vWpn[no]->getName() << "���w������" << endl
			<< "�U���͂�" << vWpn[no]->getAtk() << "�A�b�v" << endl
			<< "�d�ʂ�" << vWpn[no]->getWeight() << "������" << endl;
		}
	}
	else
	{
		cout << "���̕���͍w���ł��܂���" << endl;
		cout << "0�`" << vWpn.size() - 1 << "�͈̔͂œ��͂��Ă�������";
	}

	return 0;
}