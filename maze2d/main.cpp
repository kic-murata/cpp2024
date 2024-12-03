#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
#include "battle.h"
#include <random>
#include <algorithm>

using namespace std;

int main()
{
  Map map;
  //CSVからのデータ読み込み&マップデータの格納
  map.Load("2d_maze22.csv");
  //宝箱の生成
  map.setTreasure();

  //プレイヤーの出現位置の設定(X,Y) = (2,2)
  Player player(2,2);

  //戦闘モード
  Battle btl;

  //乱数生成 1/1000の確率を作る
  //random_device rand_dev{};
  //mt19937 rand_engine(rand_dev());
  //bernoulli_distribution dist(0.001);

  //int j = 0;
  //for (int i = 0; i < 10000; ++i) {
  //  if (dist(rand_engine)) {
  //    j++;
  //  }
  //}
  //cout << "あたり回数:" << j << endl;


  //system("cls");  //コマンドプロンプトの画面消去
  while (true)    //ゲームループ
  {
    // 標準出力画面のカーソル位置を(0,0)へ設定する
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });

    map.DrawMap(player.getX(), player.getY());
    //map.DrawMap(2, 2);

    char input = _getch();

    if (player.move(input, map.mapdata) == 99) {
      if (btl.Initialize() == 0) {
        cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
        return 0;
      }
      else {
        cout << "\033[31mゲームオーバー…\033[m" << endl;
        return 0;
      }
    }
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
