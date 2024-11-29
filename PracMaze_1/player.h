#pragma once
#include "maze.h"
using namespace std;
struct Vector2 {//構造体Vector2
	int x, y;     //メンバ変数（自キャラ座標）
	Vector2(int x, int y) :x(x), y(y) {};//コンストラクタ
};
class Player {
private:
	Vector2 Pos;         //構造体変数Pos
public:
	Player();            //引数なしコンストラクタ
	Player(int x, int y);//引数ありコンストラクタ
	void setX(int x);    //セッター
	void setY(int y);
	int getX();          //ゲッター
	int getY();
	//第一引数はwasdのいずれか、第二引数はマップデータのある二次元配列
	void move(char key, MapData& mapdata);

	
};