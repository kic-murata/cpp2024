#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
	//�p�P��̘a����L�[�A�p�P���l�Ƃ���map�R���e�idic�Ɋi�[
	map<string, string> dic{ {"����","activity"}
	,{"���͋C","atomosphere"},{"���t","blood"}
	,{"��","environment"},{"���x","temperature"} };
	auto it = dic.begin();//�擪�v�f�̃C�e���[�^���擾
	cout << it->first << endl;//first���L�[�Asecond���l
	return 0;
}