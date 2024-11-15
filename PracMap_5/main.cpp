#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct {		//�\����Enemy
	string name;			//������name
	int hp, atk, def;	//�����lhp,atk,def
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
		,{"Wolf",20,30,1},{"Spider",30,15,5} };
	map<string, Enemy> mapEne;

	for (int i = 0; i < vEne.size(); i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
		//mapEne[vEne[i].name] = vEne[i];
	}
	//for (auto v : vEne) {
	//	mapEne.emplace(v.name, v);
	//}
	string input;
	cout << "Enemy�������>";
	cin >> input;
	if (mapEne.count(input)) {
		//�C�e���[�^���g�����\��
		//auto it = mapEne.find(input);
		//cout << "Name: " << it->second.name << endl
		//	<< "Hp: " << it->second.hp << endl
		//	<< "Atk: " << it->second.atk << endl
		//	<< "Def: " << it->second.def << endl;
		cout << "Name: " << mapEne[input].name << endl
			<< "Hp: " << mapEne[input].hp << endl
			<< "Atk: " << mapEne[input].atk << endl
			<< "Def: " << mapEne[input].def << endl;
	}

	return 0;
}