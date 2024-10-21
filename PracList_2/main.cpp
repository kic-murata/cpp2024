#include<list>
#include<iostream>
using namespace std;
int main() {
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1�̖�����li2�̗v�f��ǉ����ĘA��
		for (auto d : li2) { //�A���p���[�v
			li1.push_back(d);
		}
		for (auto d : li1) { //�\���p���[�v
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li2�̐擪��li1�̖������珇�ɒǉ�
		for (auto itr = li1.rbegin()
			; itr != li1.rend(); itr++) { //�A���p���[�v
			li2.push_front(*itr);
		}
		for (auto d : li2) { //�\���p���[�v
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//merge�֐����g�����A��
		li1.merge(li2);
		for (auto d : li1) { //�\���p���[�v
			cout << d << " ";
		}
		cout << endl;
	}
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//insert�֐����g�����A��
		//�������F�}������ꏊ�i�C�e���[�^�j
		//�������F�}���������f�[�^�̐擪�̏ꏊ
		//��O�����F�@�@�@�@�V�@�@�@�@�����̏ꏊ
		li1.insert(li1.end(), li2.begin(), li2.end());
		for (auto d : li1) { //�\���p���[�v
			cout << d << " ";
		}
		cout << endl;
	}
}