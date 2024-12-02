#pragma once
#include "maze.h"
using namespace std;
//構造体Vector2で自キャラのx,y座標を管理
struct Vector2 {
	int x, y;
	Vector2(int x, int y) :x(x), y(y) {};
};
class Player {
private:
	Vector2 Pos;//構造体変数Pos
public:
	Player();            //引数なしコンストラクタ
	Player(int x, int y);//引数ありコンストラクタ
	void setX(int x);    //セッター
	void setY(int y);
	int getX();          //ゲッター
	int getY();
	//移動したい方向へ移動可能かをチェックして座標を更新する
	int move(char key, MapData& mapdata);
};