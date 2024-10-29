#include<map>
#include<vector>
#include<iostream>
using namespace std;
typedef struct { //\‘¢‘ÌEnemy
	string name;
	int hp, atk, def;
} Enemy;
int main() {
	vector<Enemy> vEne{ {"Slime",10,5,8}
	,{"Wolf",20,30,1},{"Spider",30,15,5}};
	map<string, Enemy> mapEne;
	return 0;
}