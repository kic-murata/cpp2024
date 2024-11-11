#include <iostream>//cout, cin, endl
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <string>  //getline
#include <vector>  //vector<>
#include <ios>     //left, right
#include <iomanip> //setw
using namespace std;
class Weapon {
private:
	string m_name;
	int m_atk;
	int m_price;
	int m_weight;
public:
	Weapon() : m_name(""), m_atk(0), m_price(0), m_weight(0) {};
	Weapon(string name, int atk, int price, int weight)
		: m_name(name), m_atk(atk), m_price(price), m_weight(weight) {};
	~Weapon() = default;
	string getName() { return m_name; }
	int getAtk() { return m_atk; }
	int getPrice() { return m_price; }
	int getWeight() { return m_weight; }
};
int main() {
	string filename = "weapon_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���!" << endl;
		return -1;
	}
	vector<Weapon*> vWpn{};
	vector<string> vec{};
	string text;
	getline(ifs, text);//�擪�s��ǂݔ�΂�
	while (getline(ifs, text)) {//�t�@�C�������܂ň�s���ǂݍ���
		istringstream iss(text);//������X�g���[���ɕϊ�
		while(getline(iss, text, ',')) {//������X�g���[����,�ŕ���
			vec.push_back(text);
		//	cout << text << " ";
		}
		//cout << endl;
		vWpn.push_back(new Weapon(vec[0], stoi(vec[1]), stoi(vec[2]), stoi(vec[3])));
		vec.clear();
	}
	for (int i = 0; i < vWpn.size(); i++) {
		cout << i << ":" << vWpn[i]->getName() << "\t";
		if (vWpn[i]->getPrice() < 0) {
			cout << right << setw(9) << "-�񔄕i-" << endl;
		}//right �͉E���� setw(���l)�͕\������
		else {
			cout << right << setw(8) << vWpn[i]->getPrice() << "G" << endl;
		}
	}
	cout << "�ǂ̕�����w�����܂����H��";
	cin >> text;	//�L�[�{�[�h�������
	int sel = stoi(text);//�����𐔒l�ɕϊ�
	if (sel >= 0 && sel < vWpn.size()) {//�I�����͈̔̓`�F�b�N
		if(vWpn[sel]->getPrice() >= 0){//�񔄕i�łȂ����
			cout << vWpn[sel]->getName() << "���w������" << endl
				<< "�U���͂�" << vWpn[sel]->getAtk() << "�A�b�v����" << endl
				<< "�d�ʂ�" << vWpn[sel]->getWeight() << "������" << endl;
		}
		else {//�񔄕i�̏ꍇ
			cout << "�w���ł��܂���" << endl;
		}
	}
	else {//�I�����͈̔͊O����͂����ꍇ
		cout << "�ԍ�������܂���" << endl;
	}
	ifs.close();
	return 0;
}