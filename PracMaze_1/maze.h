#pragma once
#include <vector>
using namespace std;

enum MapObj {
	ROAD,    //通路：0
	WALL,    //壁　：1
	TREASURE //宝物：2
};

class MapData {
private:
	//マップデータ格納用の二次元配列
	vector<vector<int>> mapData{};
public:
	//コンストラクタ
	MapData();
	//指定した座標(x,y)のデータを返す
	int getMapValue(int x, int y);
	//指定行の列数を返す
	int getMapSize(int i);
	//配列の最大行数を返す
	int getMapSize();
	//指定行にデータ（value）を追加する
	void addMap(int j, int value);
	//二次元配列の行数を新規で一行増やす
	void resizeMap();
	//指定した座標(x,y)にデータ（value）を格納
	void setMapValue(int x, int y, int value);
};