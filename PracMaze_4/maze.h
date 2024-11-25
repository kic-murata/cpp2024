#pragma once
#include <vector>
using namespace std;
class MapData{
private:
	//マップデータ格納用int型二次元配列
	vector<vector<int>> mapData{};
public:
	//コンストラクタ
	MapData();
	//座標(x,y)のマップデータの値を取得
	int getMapValue(int x, int y);
	//指定行(i)の配列の列数を取得
	int getMapSize(int i);
  //配列の行数を取得
	int getMapSize();
  //指定行(j)にvalueを追加
	void addMap(int j, int value);
	//二次元配列の行数を増やす
	void resizeMap();
	//座標(x,y)のマップデータをvalueに更新
	void setMapValue(int x, int y, int value);
};
enum MapObj {
	ROAD,   //通路:0
	WALL,   //　壁:1
	TREASURE//宝物:2
};
