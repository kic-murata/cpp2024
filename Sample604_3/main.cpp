#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	vector<vector<int>> v0;
	vector<int> v1{10, 9, 8};//�����^�̓��I�z��v1
	vector<string> v2;//������^�̓��I�z��v2
	v1.push_back(1);//v1�̖�����1��ǉ��i�v�f��=4�j
	v1.push_back(2);//v1�̖�����2��ǉ��i�v�f��=5�j
	v1.push_back(3);//v1�̖�����3��ǉ��i�v�f��=6�j
	v2.push_back("ABC");
	v2.push_back("DEF");
	v1.pop_back();
	v1.emplace_back(4);
	cout << "v1�̗v�f��:" << v1.size() << endl;
	
	auto itrV1 = v1.begin();
	cout << "�C�e���[�^���w���v�f�̒l:" << *itrV1 << endl;
	v1.insert(itrV1 + 1, 11);
	//itrV1 = v1.begin();
	//v1.erase(itrV1 + 3);
	v1.erase(v1.begin() + 3);

	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]=" << v1[i] << endl;
	//}
	//for (auto itr = v1.begin(); itr != v1.end(); ++itr) {
	//	cout << *itr << endl;
	//}
	for (auto itr : v1) {
		cout << itr << endl;
	}

	v2.pop_back();
	v2.emplace_back("G");
	cout << "v2�̗v�f��:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	return 0;
}