#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
//#include <fstream>
//#include <sstream>
//#include <random>
//#include <algorithm>
//#include "maze2d.h"
#include "map.h"
#include "player.h"

using namespace std;

////22行×22列の二次元配列用領域を確保
//vector<vector<int>> mapdata{};
////マップデータファイル名
//static string m_filename { "2d_maze22.csv" };
//
//enum MapObj {
//  ROAD,
//  WALL,
//  TREASURE = 4
//};

int main()
{
  Map map;
  //CSVからのデータ読み込み&マップデータの格納
  map.Load(m_filename);
  //宝箱の生成
  map.setTreasure();

  //プレイヤーの出現位置の設定(X,Y) = (2,2)
  Player player(2,2);

    system("cls");  //コマンドプロンプトの画面消去
    while (true)    //ゲームループ
    {
        // 標準出力画面のカーソル位置を(0,0)へ設定する
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });

        map.DrawMap(player.getX(), player.getY());

        char input = _getch();

        player.move(input);
    }

    return 0;
}
//コマンドプロンプトで文字に色を付ける方法
//\033[30m	黒
//\033[31m	赤
//\033[32m	緑
//\033[33m	黄
//\033[34m	青
//\033[35m	マゼンダ
//\033[36m	シアン
//\033[37m	シロ
//\033[m    リセット（リセットしないと色が残る）
