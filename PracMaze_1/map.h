#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata; //MapDataクラスのインスタンス（迷路データ）
	Map();                     //コンストラクタ
	void Load(string filename);//CSVファイルの読み込み、配列への格納
	void DrawMap(int px, int py);//配列をもとに画面にマップを描画
	void SetTreasure();        //宝物を乱数で設置する
};