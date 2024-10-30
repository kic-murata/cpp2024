#include<map>
#include<vector>
#include<iostream>
using namespace std;
typedef struct {//�\����Enemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	//vEne[0]��Slime�Ɋւ���f�[�^�i�\���̕ϐ��j
	//vEne[1]��Wolf�Ɋւ���f�[�^�i�V�j
	//vEne[2]��Spider�Ɋւ���f�[�^�i�V�j
	map<string, Enemy> mapEne{};
	//vEne[0].name: Slime
	//vEne[1].name: Wolf
	//vEne[2].name: Spider
	for (int i = 0; i < vEne.size(); i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
		//mapEne[vEne[i].name] = vEne[i];
	}
	string input; //�L�[�{�[�h���͒l���󂯎��ϐ�
	cout << "Enemy����";
	cin >> input;
	if (mapEne.count(input)) {//�L�[�̗L�����`�F�b�N
		//cout << "Name: " << mapEne[input].name << endl;
		//cout << "  HP: " << mapEne[input].hp << endl;
		//cout << " Atk: " << mapEne[input].atk << endl;
		//cout << " Def: " << mapEne[input].def << endl;
		auto it = mapEne.find(input);
		cout << "Name: " << it->second.name << endl;
		cout << "  HP: " << it->second.hp << endl;
		cout << " Atk: " << it->second.atk << endl;
		cout << " Def: " << it->second.def << endl;

	}
	return 0;
}