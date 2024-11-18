#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def)
		:m_name(name),m_hp(hp),m_atk(atk),m_def(def) {};
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
		cout << "�t�@�C�����J���܂���" << endl;
		return -1;//�G���[�R�[�h:-1
	}
	vector<string> vEne{};
	vector<Enemy*> pEne{};
	string text;
	while (getline(ifs, text)) {//��s�Ԃ�ǂݎ����text�֊i�[
		istringstream iss(text);//������X�g���[���ɕϊ�
		while (getline(iss, text, ',')) {//�X�g���[����[,]�ŕ���
			vEne.push_back(text);
		}
		pEne.push_back(new Enemy(vEne[0], stoi(vEne[1])
			, stoi(vEne[2]), stoi(vEne[3])));
		//stoi: ������𐮐��l�ɕϊ�����֐�
		vEne.clear();//vEne�̑S�v�f���폜
	}
	ifs.close();//�t�@�C�������
	for (auto p : pEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	//test.csv���㏑�����[�h�ŃI�[�v������
	ofstream ofs("test.csv", ios::out);
	if (ofs.fail()) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	ofs << "test" <<endl;
	ofs.close();
	//������enemy_list.csv�ɒǋL����
	ofs.open(filename, ios::app);
	ofs << pEne[0]->getName() << ","
		<< pEne[0]->getHp() << ","
		<< pEne[0]->getAtk() << ","
		<< pEne[0]->getDef() << endl;
	ofs.close();
	return 0;
}