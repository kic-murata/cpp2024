#include <iostream>
#include <vector>
using namespace std;
void display(int max, int min) {
	cout << "�ő�l:" << max << endl
		<< "�ŏ��l:" << min << endl;
}
//compare(int& max, int& min, int v)
// ��1�����F�ő�l���i�[����ϐ��̃A�h���X
// ��2�����F�ő�l���i�[����ϐ��̃A�h���X
// ��3�����F��r�Ώۂ̕ϐ��l
void compare(int& max, int& min, int v) {
	if (max < v) {
		max = v;
	}
	if (min > v) {
		min = v;
	}
}

int main() {
	vector<int> vec{ 20, 11, 9, 33, 40, 25 };
	int max, min;
	//�����_��
	auto disp = [](int a, int b) {
		cout << "�ő�l:" << a << endl
			<< "�ŏ��l:" << b << endl;
		};
	//�Y�����ԍ����g�����ő�l�E�ŏ��l�̌���
	max = min = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
		//if (max < vec[i]) {
		//	max = vec[i];
		//}
		//if (min > vec[i]) {
		//	min = vec[i];
		//}
	}
//	display(max, min);
	disp(max, min);
	cout << "���l���ЂƂ���:";
	int a = 0;
	cin >> a;
	vec.emplace_back(a);
	//�C�e���[�^��p������@
	max = min = vec[0];
	for (auto itr = vec.begin() + 1; itr != vec.end(); itr++) {
		compare(max, min, *itr);
		//if (max < *itr) {
		//	max = *itr;
		//}
		//if (min > *itr) {
		//	min = *itr;
		//}
	}
	display(max, min);
	cout << "���l���ЂƂ���:";
	cin >> a;
	vec.emplace_back(a);
	//�͈�for
	max = min = vec[0];
	for (auto itr : vec) {
		compare(max, min, itr);
		//if (max < itr) {
		//	max = itr;
		//}
		//if (min > itr) {
		//	min = itr;
		//}
	}
	display(max, min);
	return 0;
}