#include <list>
#include <iostream>
using namespace std;
int main() {
	{	//li1�̌���li2��A��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto itr = li2.begin(); itr != li2.end(); itr++) {
			li1.push_back(*itr);
		}
		//for (auto d : li2) {
		//	li1.push_back(d);
		//}
		li1.sort();
		cout << "�A������li1�F";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//li2�̑O��li1��A��
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//�t�C�e���[�^���g�������[�v�Frbegin���f�[�^����,rend���擪
		for (auto itr = li1.rbegin(); itr != li1.rend(); itr++) {
			li2.push_front(*itr);
		}
		//li1.reverse();//�f�[�^����t���ɂ���
		//for (auto d : li1) {
		//	li2.push_front(d);
		//}
		li2.sort();
		cout << "�A������li2�F";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{	//merge
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "�A������merge�F";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << ":li2�̗v�f���F" << li2.size();
		cout << endl;
	}
	{	//insert
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//insert�̈���
		//��1�����F�}���������ꏊ�̃C�e���[�^
		//��2�����F�}������f�[�^�̐擪�C�e���[�^
		//��3�����F�@�@�@�@�V�@�@�̖����C�e���[�^
		li1.insert(li1.end(), li2.begin(), li2.end());
		li1.sort();
		cout << "�A������insert�F";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << ":li2�̗v�f���F" << li2.size();
		cout << endl;
	}
	{	//splice
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//splice�̈���
		//��1�����F�}���������ꏊ�̃C�e���[�^
		//��2�����F�}�����郊�X�g
		li1.splice(li1.end(), li2);
		li1.sort();
		cout << "�A������splice�F";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << ":li2�̗v�f���F" << li2.size();
		cout << endl;
	}
}