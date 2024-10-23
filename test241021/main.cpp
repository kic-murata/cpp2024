/*
vector�ɍ\���̂��i�[���āA����̃����o�̒l���g���ă\�[�g���s���T���v��
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int a, b, c;
} Item;

int main() {
	vector<Item> vec{ {11,9,8},{8,10,12},{20,5,1},{10,2,3} };
	//��O�����ɔ�r�֐��i�����_���j���L�q���āA�����~����؂�ւ�
	//����̓����oc�̑召��r�ō~���\�[�g���Ă���
	sort(vec.begin(), vec.end(), 
		[](const Item& it1, const Item& it2) { return it1.c > it2.c; }
	);

	cout << "a  b  c" <<  endl;
	for (Item it : vec) {
		cout << it.a << " " << it.b << " " << it.c << endl;
	}
}