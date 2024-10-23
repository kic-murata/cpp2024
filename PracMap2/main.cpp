#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	map<string, string> dic{ {"����","activity"},
		{"���͋C","atmosphere"},{"���t","blood"},
		{"��","environment"},{"���x","temperature"}};

	random_device rand_dev{};
	mt19937 rand_engine(rand_dev());
	uniform_int_distribution<int> dist(0, dic.size() - 1);  // 1�`6 ���ϓ��Ȋm���œ��镪�z������

	auto it = dic.begin();
	it = next(it, dist(rand_engine));
	cout << it->first << "���p��ɒ����ƁH";
	string input;
	cin >> input;
	if (input == it->second) {
		cout << "�����I" << endl;
	}
	else {
		cout << "�s����" << endl;
	}
}
