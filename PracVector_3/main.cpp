#include <vector>
#include <iostream>
using namespace std;
void compare(int& max, int& min, const int& data) {
	max = max < data ? data : max;
	min = min > data ? data : min;
	//if (max < data) {
	//	max = data;
	//}
	//if (min > data) {
	//	min = data;
	//}
}
int main() {
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�@�Y�����̔ԍ��Ń��[�v
	max = min = vec[0]; //���̍ő�l�ƍŏ��l��擪�v�f��
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	vec.emplace_back(50);
	//�A�C�e���[�^�Ń��[�v
	max = min = vec.at(0);//vec[0]��vec.at(0)�͓����Ӗ�
	for (auto itr = vec.begin(); itr != vec.end() ; itr++) {
		compare(max, min, *itr);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	vec.emplace_back(1);
	//�B�͈�for�Ń��[�v
	max = min = vec.front();
	for (auto d: vec) {
		compare(max, min, d);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
}