#pragma once
#include "maze.h"

class Map {
public:
	MapData mapdata;
	Map();
	void Load(string filename);
	void DrawMap();
};