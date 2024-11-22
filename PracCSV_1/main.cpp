#include <iostream>	//cout
#include <fstream>	//ifstream
#include <string>		//getline
#include <sstream>	//istringstream
#include <vector>		//vector
#include <iomanip>  //setw
using namespace std;
class Weapon {
private://���햼, �U����, ���i, �d��
	string m_name;
	int m_atk, m_price, m_weight;
public:
	Weapon() = default;
	//��������̃R���X�g���N�^�Ń����o�ϐ�������������
	Weapon(string name, int atk, int price, int weight)
		:m_name(name), m_atk(atk),
		 m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};

int main() {
	//�t�@�C�������w�肵�ē��̓t�@�C���X�g���[���𐶐�
	ifstream ifs("weapon_list.csv");
	//�t�@�C���I�[�v�����ɃG���[���������������`�F�b�N
	if (ifs.fail()) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	//��s���t�@�C������ǂݍ����Weapon�N���X�̃C���X�^���X�𐶐�����
	vector<Weapon*> vWpn{};//Weapon�N���X�̔z��
	vector<string> vec{};//CSV�̊e���ڂ��ꎞ�I�Ɋi�[����z��
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		//text�Ɋi�[���ꂽ���e�𕶎���X�g���[���Ƃ��Đ���
		istringstream iss(text);
		//������X�g���[�����R���}(,)�ŕ�������̂��J��Ԃ�
		while (getline(iss, text, ',')) {
			//�����������ڂ�vec�Ɋi�[
			vec.push_back(text);
		}
		//CSV�𕪊���������(vec)��Weapon�N���X�̈����Ƃ���
		//�R���X�g���N�^���ďo���A�C���X�^���X�𐶐�����B
		//vWpn�ɂ͐������ꂽ�C���X�^���X�̃A�h���X���i�[�����B
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]),
			stoi(vec[2]), stoi(vec[3])));
		//�ꎞ�I�ɕۑ����Ă������e���폜�i�v�f���͂O�j
		vec.clear();
	}
	//�t�@�C�������
	ifs.close();
	//����ꗗ�̕\��
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << left << setw(12) << vWpn[i]->getName();
		if (vWpn[i]->getPrice() >= 0) {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
		else
		{
			cout << right << setw(9) << "-�񔄕i-" << endl;
		}
	}
	//����w��
	int input;
	cout << "�ǂ̕�����w�����܂����H��";
	cin >> input;
	//���͂��ꂽ�l�����탊�X�g�̑I�������ɂ��邩�ǂ������`�F�b�N
	if (input >= 0 && input < vWpn.size()) {
		//�񔄕i���ۂ��̃`�F�b�N
		if (vWpn[input]->getPrice() < 0) {
			cout << "�񔄕i�̂��ߍw���ł��܂���I" << endl;
		}
		else {//�񔄕i�łȂ������Ƃ��͍w����̃��b�Z�[�W��\��
			cout << vWpn[input]->getName() << "���w�����܂���" << endl;
			cout << "�U���͂�" << vWpn[input]->getAtk() << "�A�b�v����" << endl;
			cout << "�d�ʂ�" << vWpn[input]->getWeight() << "������" << endl;
		}
	}
	else { //�I�����ɂȂ��ԍ�����͂����Ƃ��̕\��
		cout << "�������ԍ�����͂��Ă�������" << endl;
	}

	return 0;
}