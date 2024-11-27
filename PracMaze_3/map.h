#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapDataクラスのインスタンス（二次元配列）
	Map();	//コンストラクタ
	void Load(string filename);//CSVファイルの読み込みと格納
	void DrawMap(int px, int py);//マップ描画
	void SetTreasure();//宝物を配置する
};