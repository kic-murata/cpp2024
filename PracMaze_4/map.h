#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapDataクラスのインスタンス
	Map();
	void Load(string filename);  //CSVファイルの読み込みと配列への格納
	void DrawMap(int px, int py);//コマンドプロンプトにマップを表示
	void SetTreasure();          //宝物をマップ上に配置する
};