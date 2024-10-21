#include <iostream>
#include <vector>
using namespace std;
void compare(int& max, int& min, const int& data) {
	max = max < data ? data : max;
	min = min > data ? data : min;
}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;

	//�@�Y�����ԍ����g�������[�v
	max = min = vec[0];//���̍ő�l�ƍŏ��l��ݒ�
	for (int i = 1; i < vec.size(); i++) { //�Y�����ԍ�i�Ń��[�v
		compare(max, min, vec[i]); //compare�֐��ďo��
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�A�C�e���[�^���g�������[�v
	max = min = vec.at(0);//���̍ő�l�ƍŏ��l��ݒ�
	for (auto itr = vec.begin(); itr != vec.end(); itr++) { //�C�e���[�^�Ń��[�v
		compare(max, min, *itr); //compare�֐��ďo��
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�B�͈�for���g�������[�v
	max = min = vec.front();//���̍ő�l�ƍŏ��l��ݒ�
	for (auto d : vec) { //�͈�for�Ń��[�v
		compare(max, min, d); //compare�֐��ďo��
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
}