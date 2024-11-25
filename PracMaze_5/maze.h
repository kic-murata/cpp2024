#pragma once
#include <vector>
using namespace std;

class MapData {
private:
	vector<vector<int>> mapData{};//マップデータ格納用二次元配列
public:
	MapData();                    //コンストラクタ
	int getMapValue(int x, int y);//指定座標(x,y)のマップデータを返す
	int getMapSize(int i);        //マップデータの列数を返す
	int getMapSize();             //　　　〃　　の行数を返す
	void addMap(int j, int value);//配列の指定行(j)にvalueを追加
	void resizeMap();             //二次元配列に新しい行を追加
	void setMapValue(int x, int y, int value);//指定座標のvalueを格納
};

enum MapObj {
	ROAD,    //通路:0
	WALL,    //　壁:1
	TREASURE //宝物:2
};