/*
vector�ɍ\���̂��i�[���āA����̃����o�̒l���g���ă\�[�g���s���T���v��
*/

#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

typedef struct {
	int a, b, c;
} Item;

struct CompItem { // �召��r�p�̊֐��I�u�W�F�N�g���`����
	bool operator()(const Item& item1, const Item& item2) const noexcept {
		// �L�[�Ƃ��Ĕ�r�������v�f��񋓂���(�����c�����o�݂̂̑召��r)
		return std::tie(item1.c) < std::tie(item2.c);
	}
};

int main() {
	vector<Item> vec{ {11,9,8},{8,10,12},{20,5,1},{10,2,3} };
//	sort(vec.begin(), vec.end(), CompItem{});
	//��O�����ɔ�r�֐��i�����_���j���L�q���āA�����~����؂�ւ�
	//�����c�����o�݂̂̑召��r
	sort(vec.begin(), vec.end(), 
		[](const Item& it1, const Item& it2) { return it1.c > it2.c; }
	);
	for (Item it : vec) {
		cout << it.a << " " << it.b << " " << it.c << endl;
	}
}