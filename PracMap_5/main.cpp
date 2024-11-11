#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct {		//\‘¢‘ÌEnemy
	string name;			//•¶š—ñname
	int hp, atk, def;	//®”’lhp,atk,def
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

	return 0;
}