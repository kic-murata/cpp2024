#include <list>
#include <iostream>
using namespace std;
int main() {
	{ //�p�^�[��A
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		for (auto d : li2) {//li1�̖�����li2�̓��e��A��
			li1.push_back(d);
		}
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //�p�^�[��B
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1.reverse();//li1:17 11 3 2
		//for (auto d : li1) {//li2�̐擪��li1�̓��e��A��
		//	li2.push_front(d);
		//}
		//li1�̋t�C�e���[�^���g�������@
		// rbegin()�̓f�[�^���� rend()�̓f�[�^�擪
		for (auto it = li1.rbegin(); it != li1.rend(); it++) {
			li2.push_front(*it);
		}
		cout << "�A�����ʁF";
		for (auto d : li2) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //�p�^�[��C�imerge)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //�p�^�[��C�iinsert)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//��1�����F�}�������ꏊ�̃C�e���[�^
		//��2�����F�}������f�[�^�̐擪�̃C�e���[�^
		//��3�����F�}������f�[�^�̖����̃C�e���[�^
		li1.insert(li1.end(),li2.begin(),li2.end());
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
	{ //�p�^�[��C�isplice)
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//��1�����F�}�������ꏊ�̃C�e���[�^
		//��2�����F�}�����郊�X�g
		li1.splice(li1.end(), li2);
		cout << "�A�����ʁF";
		for (auto d : li1) {
			cout << d << " ";
		}
		cout << endl;
	}
}