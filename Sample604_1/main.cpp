#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v1{ 10,9,8 };
	vector<string> v2;
	if (v1.empty()) {
		cout << "”z—ñ‚Í‹ó‚Å‚·" << endl;
	}
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back("ABC");
	v2.push_back("DEF");
	cout << "v1‚Ì—v‘f”‚Í" << v1.size() << endl;

	for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}

	auto itrV1 = v1.begin();//itrV1‚Íæ“ª—v‘f
	cout << "itrV1‚Ì’l‚Í" << *itrV1 << endl;
	v1.erase(itrV1); //æ“ª—v‘f‚ðíœ
	v1.insert(itrV1 + 1, 7);//æ“ª—v‘f‚Ì‚Ð‚Æ‚ÂŒã‚É7‚ð‘}“ü
	

	v1.pop_back();
	v1.emplace_back(4);
	for (auto itr : v1) {
		cout << itr << endl;
	}
	
	/*for (auto itr = v1.begin(); itr != v1.end(); ++itr) {
		cout << *itr << endl;
	}*/
	/*for (int i = 0; i < v1.size(); i++) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
	}*/
	cout << "v1‚Ì—v‘f”‚Í" << v1.size() << endl;
	cout << "v2‚Ì—v‘f”‚Í" << v2.size() << endl;
	v2.pop_back();
	v2.emplace_back("G");
	for (int i = 0; i < v2.size(); i++) {
		cout << "v2[" << i << "]=" << v2[i] << endl;
	}
	cout << "v2‚Ì—v‘f”‚Í" << v2.size() << endl;
	return 0;
}