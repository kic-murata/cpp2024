#include<map>
#include<vector>
#include<iostream>
using namespace std;

typedef struct {	//�\����Enemy
	string name;
	int hp, atk, def;
} Enemy;

int main() {
	//�\����Enemy���Ǘ�����vector�z���錾
	vector<Enemy> vEne{ { "Slime",10,5,8 }
	                  , { "Wolf",20,30,1 }
	                  , { "Spider",30,15,5 } };
	//�L�[�F������A�l�F�\����Enemy��map��錾
	map<string, Enemy> mEne{};
	cout << "�G�l�~�[���X�g" << endl;
	for (const auto& d : vEne) {
		mEne.emplace(d.name, d);
		cout << "�E" << d.name << endl;
	}
	cout << "�X�e�[�^�X��\���������G�l�~�[�̖��O����́�";
	string input;
	cin >> input;
	if (mEne.count(input)) {
		cout << "Name: " << mEne[input].name << endl
			   << "  HP: " << mEne[input].hp << endl
			   << " Atk: " << mEne[input].atk << endl
			   << " Def: " << mEne[input].def << endl;
	}
	return 0;
}