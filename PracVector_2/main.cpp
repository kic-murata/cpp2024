#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//�Y�������g�������[�v
	max = min = vec[0];//���̍ő�l�ŏ��l
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�C�e���[�^���g�������[�v
	max = min = vec[0];//���̍ő�l�ŏ��l
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�͈�for���g�������[�v
	max = min = vec[0];//���̍ő�l�ŏ��l
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	return 0;
}