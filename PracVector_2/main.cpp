#include <iostream>
#include <vector>
using namespace std;
void compare(int& max, int& min, int data) {
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
	//�Y�������g�������[�v
	max = min = vec[0];//���̍ő�l�ŏ��l
	for (int i = 1; i < vec.size(); i++) {
		compare(max, min, vec[i]);
		//max = max < vec[i] ? vec[i] : max;
		//min = min > vec[i] ? vec[i] : min;
		//if (max < vec[i]) {
		//	max = vec[i];
		//}
		//if (min > vec[i]) {
		//	min = vec[i];
		//}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�C�e���[�^���g�������[�v
	vec.push_back(-10);
	//max = min = vec[0];//���̍ő�l�ŏ��l
	max = min = vec.at(0);
	for(auto itr = vec.begin();itr!=vec.end();++itr){
		for (int i = 1; i < vec.size(); i++) {
			compare(max, min, *itr);
			//if (max < *itr) {
			//	max = *itr;
			//}
			//if (min > *itr) {
			//	min = *itr;
			//}
		}
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	//�͈�for���g�������[�v
	vec.push_back(50);
	max = min = vec.front();//���̍ő�l�ŏ��l
	for (auto itr : vec) {
		compare(max, min, itr);
	}
	cout << "�ő�l:" << max << " �ŏ��l:" << min << endl;
	return 0;
}