#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef struct {	//Enemy�\����
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8},
		{"Wolf",20,30,1},{"Spider",30,30,5} };
	map<string, Enemy> mapEne{};
	//vEne[0] : Slime�̏�񂪓������\���̕ϐ�
	//vEne[1] : Wolf�̏�񂪓������\���̕ϐ�
	//vEne[2] : Spider�̏�񂪓������\���̕ϐ�
	//vEne[0].name : "Slime"
	for (int i = 0; i < vEne.size();i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
	}
	string input;
	cout << "Enemy������́�";
	cin >> input;
	//mapEne[�L�[��]�Œl�i�\���́j�����o���\
	//mapEne["Wolf"].hp �Ȃ�Wolf��HP���擾�\
	cout << input << "�̏��F" << endl
		<< "Name:" << mapEne[input].name << endl
		<< "HP:" << mapEne[input].hp << endl
		<< "ATK:" << mapEne[input].atk << endl
		<< "DEF:" << mapEne[input].def << endl;



	return 0;
}