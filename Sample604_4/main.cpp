#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	vector<int> v1{ 10, 9, 8 };
	vector<string> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back("ABC");
	v2.push_back("DEF");
	v1.pop_back();
	v1.emplace_back(4);
	cout << "v1�̗v�f��:" << v1.size() << endl;

	auto itr = v1.begin();
	cout << "�C�e���[�^�̎w���ꏊ�̒l:" << *itr << endl;
	v1.insert(itr + 2, 20);
	itr = v1.begin();
	v1.erase(itr + 4);
	// �Y�������g�������[�v
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << "v1[" << i << "]=" << v1[i] << endl;
	//}
	// �C�e���[�^���g�������[�v
	//for (auto itr = v1.begin(); itr != v1.end(); itr++) {
	//	cout << *itr << endl;
	//}
	// �͈�for���g�������[�v
	for (auto d : v1) {
		cout << d << endl;
	}
	v2.pop_back();
	v2.emplace_back("G");
	cout << "v2�̗v�f��:" << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	return 0;
}