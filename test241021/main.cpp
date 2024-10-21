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
	sort(vec.begin(), vec.end(), CompItem{});
	for (Item it : vec) {
		cout << it.a << " " << it.b << " " << it.c << endl;
	}
}