#include<map>
#include<vector>
#include<iostream>
using namespace std;
typedef struct {//構造体Enemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	//vEne[0]はSlimeに関するデータ（構造体変数）
	//vEne[1]はWolfに関するデータ（〃）
	//vEne[2]はSpiderに関するデータ（〃）
	map<string, Enemy> mapEne{};
	//vEne[0].name: Slime
	//vEne[1].name: Wolf
	//vEne[2].name: Spider
	for (int i = 0; i < vEne.size(); i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
		//mapEne[vEne[i].name] = vEne[i];
	}
	string input; //キーボード入力値を受け取る変数
	cout << "Enemy名＞";
	cin >> input;
	if (mapEne.count(input)) {//キーの有無をチェック
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