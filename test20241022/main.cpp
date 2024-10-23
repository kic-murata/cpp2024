#include<map>
#include<vector>
#include<iostream>
using namespace std;

typedef struct {	//構造体Enemy
	string name;
	int hp, atk, def;
} Enemy;

int main() {
	//構造体Enemyを管理するvector配列を宣言
	vector<Enemy> vEne{ { "Slime",10,5,8 }
	                  , { "Wolf",20,30,1 }
	                  , { "Spider",30,15,5 } };
	//キー：文字列、値：構造体Enemyのmapを宣言
	map<string, Enemy> mEne{};
	cout << "エネミーリスト" << endl;
	for (const auto& d : vEne) {
		mEne.emplace(d.name, d);
		cout << "・" << d.name << endl;
	}
	cout << "ステータスを表示したいエネミーの名前を入力＞";
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