/* ���̃v���O�����̃\�[�X�R�[�h�͈ȉ���URL�Ŕz�z
https://bit.ly/4iffoE2
*/
#include<iostream>
#include<vector>
using namespace std;

//Parent�N���X�̒�`
class Parent {
public:
	//�R���X�g���N�^�i�R���X�g���N�^�ƃI�[�o�[�H�H�H�j
	Parent() {};
	Parent(int age, double height, double weight, string name)
	:age(age), height(height), weight(weight), name(name) {};
	/* ��������̃R���X�g���N�^���g�����ƂŁA
	   �C�j�V�����C�U�ɂ���ă����o�ϐ���
		 �R���X�g���N�^�̏������O�ɏ����� */
	//�H�H�H���N�^
	~Parent() {};
	//�H�H�֐�
	virtual int getData() { return age; }
	//���O���擾����Q�b�^�[
	string getName() { return name; }
private:
	//�N��age�E�g��height�E�̏dweight�E���Oname
	int age;
	double height;
	double weight;
	string name;
//public,private,protected���H�H�H�H�w��q�ƌĂ�
};

//Parent�N���X���H�H����Child�N���X�̒�`�@
class Child : public Parent {
public:
	//�R���X�g���N�^
	Child() {};
	Child(int age, double height, double weight, string name)
		:Parent(age, height, weight, name) ,data(weight/(height*height)*10000) {};
	//�f�X�g���N�^
	~Child() {};
	//�e�N���X�̊֐��̃I�[�o�[�H�H�H
	int getData() { return data; }
private:
	int data;
};

//Family�N���X�̒�`
class Family {
public:
	//�R���X�g���N�^
	Family() {};
	Family(vector<Child*> vec) { family_num = vec.size(); }
	//�f�X�g���N�^
	~Family() {};
	//�Q�b�^�[�֐�
	int getFamily() { return family_num; }
private:
	int family_num;
};

int main() {
	//Parent�N���X�̃C���X�^���X����
	Parent p(40, 173.2, 65.5, "���Y");
	cout << p.getName() << "�̔N���" << p.getData() << "��" << endl;

	//Child�N���X�̃C���X�^���X����
	Child c(15, 160.8, 53.2, "��Y");
	cout << c.getName() << "��BMI��" << c.getData()  << endl;

	/* �ϒ��z��vector�̐錾
	 �i�i�[�ł���̂�Child�N���X�̃C���X�^���X�́H�H�H�H�j*/
	vector<Child*> vc{};
	//���łɐ��������C���X�^���X�́H�H�H�H��z�񖖔��ɒǉ�
	vc.push_back(&c);
	//new���Z�q���g���ăC���X�^���X�𐶐����Ă��́H�H�H�H��z�񖖔��ɒǉ�
	vc.push_back(new Child(10, 142.5, 40.1, "���Y"));
	vc.push_back(new Child(8, 125.3, 32.6, "�Ԏq"));

	//�H�Hfor����p�������[�v����
	for (auto c : vc) {
		//�z��e�v�f�́H�H�H�H�Ȃ̂ŁA�����o�֐����Ăяo���ۂ́H�H�H���Z�q���g�p
		cout << "�q���̖��O��" << c->getName() << endl;
	}

	//Family�N���X�̃C���X�^���X�𐶐����ď����l�ɔz��vc���w�肷��
	Family f(vc);
	cout << "�q���̐l����" << f.getFamily() << "�l" << endl;

	return 0;
}