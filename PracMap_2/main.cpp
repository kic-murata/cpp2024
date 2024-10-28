#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef struct {	//Enemy構造体
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8},
		{"Wolf",20,30,1},{"Spider",30,30,5} };
	map<string, Enemy> mapEne{};
	//vEne[0] : Slimeの情報が入った構造体変数
	//vEne[1] : Wolfの情報が入った構造体変数
	//vEne[2] : Spiderの情報が入った構造体変数
	//vEne[0].name : "Slime"
	for (int i = 0; i < vEne.size();i++) {
		mapEne.emplace(vEne[i].name, vEne[i]);
	}
	string input;
	cout << "Enemy名を入力＞";
	cin >> input;
	//mapEne[キー名]で値（構造体）を取り出し可能
	//mapEne["Wolf"].hp ならWolfのHPが取得可能
	cout << input << "の情報：" << endl
		<< "Name:" << mapEne[input].name << endl
		<< "HP:" << mapEne[input].hp << endl
		<< "ATK:" << mapEne[input].atk << endl
		<< "DEF:" << mapEne[input].def << endl;



	return 0;
}