#include <iostream>
#include <set>
#include <string>

class Chara {
public:
	int a_;
private:
	int b_;
};

using namespace std;
int main() {
	Chara c;
	c.a_ = 10;
	cout << "a=" << c.a_ << endl;
	set<string> names{ "John", "Sam"}; //�����l�̐ݒ�
	names.insert("Tom");
	names.insert("Mike");
	names.insert("Mike"); //�d���L�[�̓o�^
	names.insert("Bob");
	names.erase("Sam");  //�L�[�̍폜
	/*for (auto it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}*/
	for (auto it : names) { //�͈�for
		cout << it << endl;
	}
	string n[] = { "Bob","Steve" }; //��������L�[2��
	for (int i = 0; i < size(n); i++) {
		auto it = names.find(n[i]); //�L�[�����ԂɌ���
		if (it == names.end()) { //�L�[��������Ȃ�����
			cout << n[i] << " is not in a set." << endl;
		}
		else { //�L�[����������
			cout << n[i] << " is in a set." << endl;
		}
	}
	auto it1 = names.lower_bound("Mike");
	cout << *it1 << endl; //Mike��菬�����Ȃ��ŏ��̃L�[
	auto it2 = names.upper_bound("John");
	cout << *it2 << endl; //John���傫���ŏ��̃L�[
	return 0;
}