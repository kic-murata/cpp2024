#include <vector>
#include <iostream>
using namespace std;
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	//�@�Y�����̔ԍ��Ń��[�v
	max = min = vec[0]; //���̍ő�l�ƍŏ��l��擪�v�f��
	for (int i = 1; i < vec.size(); i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
		if (min > vec[i]) {
			min = vec[i];
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	vec.emplace_back(50);
	//�A�C�e���[�^�Ń��[�v
	max = min = vec.at(0);//vec[0]��vec.at(0)�͓����Ӗ�
}