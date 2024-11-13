#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk), m_def(def) {};
	~Enemy() = default;
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};


int main() {
	string filename = "enemy_list.csv";
	ifstream ifs(filename);
	if (ifs.fail()) {
		cout << "�t�@�C�����J���܂���I" << endl;
		return -1;
	}
	vector<string> vEne{};//�ꎟ���z��̐錾
	vector<Enemy*> pEne{};//Enemy�N���X�̔z��
	string text;
	//int j = 0;
	while (getline(ifs, text)) {//��s����CSV����ǂݍ���
		istringstream iss(text);//������X�g���[���ɕϊ�
		//vEne.resize(j+1);
		while (getline(iss, text, ',')) {//������X�g���[����','�ŕ���
			//vEne[j].push_back(text);//�����������ڂ�z��֊i�[
			vEne.push_back(text);//�����������ڂ�z��֊i�[
		}
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1]),
			stoi(vEne[2]), stoi(vEne[3])));
		vEne.clear();
		//for (auto d : vEne[j]) {//�͈�for�Ŕz��̑S�v�f��\��
		//	cout << d << endl;
		//}
		//j++;
	}
	ifs.close();
	for (const auto& p : pEne) {
		cout << p->getName() << "\t" << p->getHp() << "\t"
			<< p->getAtk() << "\t" << p->getDef() << endl;
	}
	string ofilename = "enemy_list2.csv";
	ofstream ofs(ofilename, ios::out);//�㏑�����[�h
	if (ofs.fail()) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	for (const auto& p : pEne) {
		ofs << p->getDef() << "," << p->getAtk() << ","
			<< p->getHp() << "," << p->getName() << endl;
	}
	ofs.close();
	ofs.open(ofilename, ios::app);
	ofs << "4,10,25,Rat" << endl;
	ofs.close();
	return 0;
}