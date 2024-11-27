#pragma once
#include "maze.h"
using namespace std;
//構造体Vector2
struct Vector2 {
	int x, y;//自キャラのx,y座標を管理する
	Vector2(int x, int y) :x(x), y(y) {};
};
class Player {
private:
	Vector2 Pos;	//構造体Vector2型変数Pos
public:
	Player();             //コンストラクタ（引数なし）
	Player(int x, int y); //コンストラクタ（引数あり）
	void setX(int x);     //セッター
	void setY(int y);
	int getX();           //ゲッター
	int getY();
	//マップ上で移動可能かどうかを調べて、自キャラ座標を更新する
	void move(char key, MapData& mapdata);
};