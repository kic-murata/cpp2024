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
	set<string> names{ "John", "Sam"}; //初期値の設定
	names.insert("Tom");
	names.insert("Mike");
	names.insert("Mike"); //重複キーの登録
	names.insert("Bob");
	names.erase("Sam");  //キーの削除
	/*for (auto it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}*/
	for (auto it : names) { //範囲for
		cout << it << endl;
	}
	string n[] = { "Bob","Steve" }; //検索するキー2つ
	for (int i = 0; i < size(n); i++) {
		auto it = names.find(n[i]); //キーを順番に検索
		if (it == names.end()) { //キーが見つからなかった
			cout << n[i] << " is not in a set." << endl;
		}
		else { //キーが見つかった
			cout << n[i] << " is in a set." << endl;
		}
	}
	auto it1 = names.lower_bound("Mike");
	cout << *it1 << endl; //Mikeより小さくない最初のキー
	auto it2 = names.upper_bound("John");
	cout << *it2 << endl; //Johnより大きい最初のキー
	return 0;
}