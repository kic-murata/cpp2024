#include<map>
#include<vector>
#include<iostream>
using namespace std;
typedef struct { //構造体Enemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	map<string, Enemy> mapEne;
	//範囲forを用いたmapコンテナへのvEneの格納
	//for (const auto& d : vEne) {
	//	mapEne.emplace(d.name, d);
	//}
	//添え字番号を用いたmapコンテナへのvEneの格納
	for (int i = 0; i < vEne.size(); i++) {
		mapEne[vEne[i].name] = vEne[i];
	}
	string input;
	cout << "Enemy名を入力>";
	cin >> input;//Enemy名をキーボード入力してinputへ
	if (mapEne.count(input)) {
		cout << "Name:" << mapEne[input].name << endl
			<< "Hp:" << mapEne[input].hp << endl
			<< "Atk:" << mapEne[input].atk << endl
			<< "Def:" << mapEne[input].def << endl;
	}
	return 0;
}