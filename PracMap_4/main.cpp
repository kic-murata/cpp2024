#include <vector>
#include <map>
#include <iostream>
using namespace std;
typedef struct {//構造体Enemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	map<string, Enemy> mapEne;
	//vEne[0].name: Slime
	//vEne[1].name: Wolf
	//vEne[2].name: Spider
	for (int i = 0; i < vEne.size(); i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
		//mapEne[vEne[i].name] = vEne[i];
	}
	string input;//キー入力値の受け取り用変数
	cout << "Enemy名を入力＞";
	cin >> input;//キー入力　＞　input へ格納
	if (mapEne.count(input)) {
		//auto it = mapEne.find(input);
		//cout << "Name: " << it->second.name << endl;
		//cout << "HP: " << it->second.hp << endl;
		//cout << "ATK: " << it->second.atk << endl;
		//cout << "DEF: " << it->second.def << endl;

		cout << "Name: " << mapEne[input].name << endl;
		cout << "HP: " << mapEne[input].hp << endl;
		cout << "ATK: " << mapEne[input].atk<< endl;
		cout << "DEF: " << mapEne[input].def << endl;
	}
	return 0;
}