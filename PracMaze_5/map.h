#pragma once
#include "maze.h"
#include <iostream>

class Map {
public:
	MapData mapdata;//MapDataクラスのインスタンス
	Map();          //コンストラクタ
	void Load(string filename);//CSVファイルの読み込みと配列への格納
	void DrawMap(int px, int py); //マップデータの画面表示
	void SetTreasure();//宝物の場所を乱数で決定
};