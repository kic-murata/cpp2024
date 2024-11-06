#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"����","activity"},
		{"���͋C","atmosphere"},{"���t","blood"},
		{"��","environment"},{"���x","temperature"}};
	auto it = dic.begin();
	cout << "�擪�v�f�F" << it->first << endl;
	//�C�e���[�^�̃��[�v
	//for (it = dic.begin(); it != dic.end(); it++) {
	//	cout << it->first << endl;
	//}
	//�͈�for�̃��[�v
	for (const auto& p : dic) {
		cout << p.first << endl;
	}
	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	uniform_int_distribution<int> dist(0, dic.size() - 1);
	//cout << dist(rand_engine);

	it = dic.begin();
	it = next(it, dist(rand_engine));
	cout << it->first << "�̉p�P��́H" << endl;
	string input;
	cin >> input;
	if (input == it->second) {
		cout << "�����I" << endl;
	}
	else {
		cout << "�s�����c" << endl;
	}

	return 0;
}