#include <iostream>//cout, string, endl
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
		:m_name(name), m_atk(atk)
		, m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	ifstream ifs("weapon_list.csv");
	if (ifs.fail()) {
		cout << "error" << endl;
		return -1;
	}
	vector<Weapon*> vWpn{};//Weapon�N���X�̔z��
	vector<string> v{};//�ꎞ�I��CSV�̊e���ڂ��i�[����z��
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		istringstream iss(text);
		while (getline(iss, text, ',')) {
			v.push_back(text);//�����������ڂ�z��֒ǉ�
		}
		//CSV���番���������ڂ�Weapon�N���X�̃R���X�g���N�^�̈����Ƃ���
		//�C���X�^���X�𐶐����A���̃C���X�^���X�̃A�h���X��vWpn�֊i�[
		vWpn.push_back(new Weapon(v[0], stoi(v[1]), stoi(v[2])
			, stoi(v[3])));
		v.clear();//�z��̗v�f�����ׂč폜
	}
	ifs.close();
	//����ꗗ�̕\���F�u�ʂ��ԍ��F���햼�@���i�v
	for (int i = 0; i < vWpn.size(); i++) {
		//�ʂ��ԍ��F���햼
		cout << i << ":" << left << setw(10) << vWpn[i]->getName();
		//���i
		if (vWpn[i]->getPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
		else {
			cout << right << setw(9) << "-�񔄕i-" << endl;
		}
	}
	//����w�����
	cout << "�ǂ̕�����w�����܂����H>";
	int i;   //�w�����镐��̔ԍ����i�[����ϐ�
	cin >> i;//�L�[�{�[�h���琔�������
	if (i >= 0 && i < vWpn.size()) {//���탊�X�g�͈͓̔������`�F�b�N
		if (vWpn[i]->getPrice() < 0) {//�񔄕i�̂Ƃ�
			cout << "�񔄕i�̂��ߍw���ł��܂���" << endl;
		}
		else
		{ //�񔄕i�ł͂Ȃ��Ƃ��̏���
			cout << vWpn[i]->getName() << "���w������" << endl;
			cout << "�U���͂�" << vWpn[i]->getAtk() << "�A�b�v����" << endl;
			cout << "�d�ʂ�" << vWpn[i]->getWeight() << "������" << endl;
		}
	}
	else
	{ //���탊�X�g�̔ԍ��ȊO�����͂��ꂽ�Ƃ��̏���
		cout << "���̔ԍ��̕���͂���܂���" << endl;
	}
	return 0;
}