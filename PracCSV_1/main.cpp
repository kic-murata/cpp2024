#include <iostream>	//cout
#include <fstream>	//ifstream
#include <string>		//getline
#include <sstream>	//istringstream
#include <vector>		//vector
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
};

int main() {
	//�t�@�C�������w�肵�ē��̓t�@�C���X�g���[���𐶐�
	ifstream ifs("weapon_list.csv");
	//�t�@�C���I�[�v�����ɃG���[���������������`�F�b�N
	if (ifs.fail()) {
		cout << "�t�@�C���I�[�v���G���[" << endl;
		return -1;
	}
	//��s���t�@�C������ǂݍ���ŕ\�����J��Ԃ�
	string text;
	getline(ifs, text);//��s�ڂ�ǂݎ̂Ă�
	while (getline(ifs, text)) {
		//text�Ɋi�[���ꂽ���e�𕶎���X�g���[���Ƃ��Đ���
		istringstream iss(text);
		//������X�g���[�����R���}(,)�ŕ�������̂��J��Ԃ�
		while (getline(iss, text, ',')) {
			//�����������ڂƋ󔒂�\��
			cout << text << " ";
		}
		//���s��\��
		cout << endl;
	}
	//�t�@�C�������
	ifs.close();
	return 0;
}