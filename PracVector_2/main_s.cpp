#include <iostream>
#include <vector>
using namespace std;
//�Q�Ɠn����p����compare�֐�
//void compare(int& max, int& min, int data) {
//	max = max < data ? data : max;
//	min = min > data ? data : min;
//}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//�����_����p����compare�֐�
	auto compare = [](int& max, int& min, int data) { 
		max = max < data ? data : max; 
		min = min > data ? data : min; 
	};
	//*** �Y�������g�������[�v
	max = min = vec[0];			//���̍ő�l�ŏ��l�Ƃ��Đ擪�v�f����
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//*** �C�e���[�^���g�������[�v
	vec.push_back(-10);			//�f�[�^(-10)��ǉ�
	max = min = vec.at(0);	//���̍ő�l�ŏ��l�Ƃ��Đ擪�v�f����
	for(auto itr = vec.begin(); itr != vec.end(); ++itr){
		compare(max, min, *itr);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//*** �͈�for���g�������[�v
	vec.push_back(50);			//�f�[�^(50)��ǉ�
	max = min = vec.front();//���̍ő�l�ŏ��l�Ƃ��Đ擪�v�f����
	for (auto itr : vec) {
		compare(max, min, itr);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	return 0;
}