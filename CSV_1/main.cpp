#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Enemy {
private:
	string m_name;
	int m_hp, m_atk, m_def;
public:
	Enemy() = default;
	Enemy(string name, int hp, int atk, int def)
		:m_name(name), m_hp(hp), m_atk(atk)
		, m_def(def) {};
	~Enemy() = default;
	string getName() { return m_name; }
	int getHp() { return m_hp; }
	int getAtk() { return m_atk; }
	int getDef() { return m_def; }
};
int main() {
	string filename = "enemy_list.csv";
	//�t�@�C�����͗p�X�g���[��ifs�𐶐����ăI�[�v��
	ifstream ifs(filename);
	if (ifs.fail()) {//�G���[�`�F�b�N
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;     //�G���[�R�[�h�F-1
	}
	vector<Enemy*> vEne{};//Enemy�N���X�̔z��
	vector<string> v{};//CSV�̊e���ڂ��ꎞ�ۑ�����z��
	string text;
	while (getline(ifs, text)) {//�t�@�C�������s�ǂݍ���
		istringstream iss(text);//������X�g���[������
		while (getline(iss, text, ',')) {
			v.push_back(text);//�z��Ɋe���ڂ��ꎞ�I�Ɋi�[
		}
		//�z��v�̊e�v�f��Enemy�̃R���X�g���N�^�̈����ɂ���
		//�C���X�^���X�����@��stoi()�͕�����𐮐��ɕϊ�����
		vEne.push_back(new Enemy(v[0], stoi(v[1]),
			stoi(v[2]), stoi(v[3])));
		v.clear();//�z��v�̑S�v�f���폜
	}
	ifs.close();
	for (auto p : vEne) {
		cout << p->getName() << "\t"
			<< p->getHp() << "\t"
			<< p->getAtk() << "\t"
			<< p->getDef() << endl;
	}
	//�o�̓t�@�C���X�g���[���̐���
	ofstream ofs("enemy_list2.csv", ios::out);
	if (!ofs) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	ofs << "test" << "," << 100 << "," << 20 << endl;
	ofs.close();
	ofs.open("enemy_list.csv", ios::app);
	ofs << "Rat,50,5,2" << endl;
	ofs.close();
	return 0;
}