#include<vector>
#include<iostream>
using namespace std;
int main() {
	vector<int> vec{ 20, 11, 9, 33, 40, 25 };
	int max, min;
	//�@�Y�����ԍ����g�������[�v
	max = min = vec[0]; //���̍ő�l�ŏ��l��擪�v�f��
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�A�C�e���[�^���g�������[�v
	max = min = vec.at(0);
	for(auto itr = vec.begin(); itr != vec.end(); itr++) {
		if (max < *itr) {
			max = *itr;
		}
		if (min > *itr) {
			min = *itr;
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�B�͈�for���g�������[�v
	max = min = vec.front();
	for (auto d : vec) {
		if (max < d) {
			max = d;
		}
		if (min > d) {
			min = d;
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;

}