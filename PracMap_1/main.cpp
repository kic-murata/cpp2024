#include<map>
#include<vector>
#include<iostream>
using namespace std;
typedef struct { //�\����Enemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	map<string, Enemy> mapEne;
	//�͈�for��p����map�R���e�i�ւ�vEne�̊i�[
	//for (const auto& d : vEne) {
	//	mapEne.emplace(d.name, d);
	//}
	//�Y�����ԍ���p����map�R���e�i�ւ�vEne�̊i�[
	for (int i = 0; i < vEne.size(); i++) {
		mapEne[vEne[i].name] = vEne[i];
	}
	string input;
	cout << "Enemy�������>";
	cin >> input;//Enemy�����L�[�{�[�h���͂���input��
	if (mapEne.count(input)) {
		cout << "Name:" << mapEne[input].name << endl
			<< "Hp:" << mapEne[input].hp << endl
			<< "Atk:" << mapEne[input].atk << endl
			<< "Def:" << mapEne[input].def << endl;
	}
	return 0;
}