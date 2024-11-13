#pragma once
#include "maze2d.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
class Map {
public:
  Map() = default;
  void Load(string filename) {
    ifstream ifs(filename);
    if (!ifs) {
      cout << "FileOpen Error" << endl;
      exit(-1);
    }
    string linetext;
    //vector<int> strvec{};
    int j = 0;
    // ファイルの終わりまで一行ずつ読み込んでいく
    while (getline(ifs, linetext)) {
      // 読み込んだ一行をsplit関数で分割して、vector型のstrvecへ格納する
      mapdata.resize(mapdata.size() + 1);
      istringstream iss(linetext);
      while (getline(iss, linetext, ',')) {
        mapdata[j].push_back(stoi(linetext));
      }
      j++;
    }
  }
  void setTreasure() {
    // 乱数生成器のオブジェクトrnd_devを作成
    random_device rnd_dev{};
    // 疑似乱数（メルセンヌツイスター）のために初期シード（乱数）を与える
    mt19937 rand_engine(rnd_dev());
    // X座標用の範囲を指定した分布生成器オブジェクトrnd_xを生成
    uniform_int_distribution<int> rnd_x(2, mapdata[0].size() - 3);
    // Y座標用の範囲を指定した分布生成器オブジェクトrnd_yを生成
    uniform_int_distribution<int> rnd_y(2, mapdata.size() - 3);
    //指定範囲（2～19の範囲）で乱数を生成する
    auto trX = rnd_x(rand_engine);
    auto trY = rnd_y(rand_engine);
    if (mapdata[trY][trX] == ROAD) {//宝箱の位置が道の上にあればOK
      mapdata[trY][trY] = TREASURE;
    }
    else
    { //壁の中に宝箱が設定されたらもう一度やり直し
      setTreasure();
    }
  }
  void DrawMap(int playerX, int playerY) {
  //マップはプレイヤーの位置を中心として、5×5マスぶんだけ画面に表示
  // #####
  // # ###
  // # @
  // # ###
  // # ###
  //そのため、プレイヤーの位置からX座標、Y座標ともに２マスぶん小さい
  //ところから、２マスぶん大きい座標までの間のデータを画面に表示する
    for (int y = playerY - 2; y <= playerY + 2; y++)
    {
      for (int x = playerX - 2; x <= playerX + 2; x++)
      {
        if (x == playerX && y == playerY)   //プレイヤーのいる座標に
        {
          //cout << PLAYER;                 //プレイヤーの文字を表示
          cout << "@";                 //プレイヤーの文字を表示
        }
        else
        {
          //プレイヤー以外の場所を表示
          if (mapdata[y][x] == WALL) {
            cout << "\033[31m#\033[m";
          }
          if (mapdata[y][x] == ROAD) {
            cout << "\033[30m.\033[m";
          }
          if (mapdata[y][x] == TREASURE) {
            cout << "\033[33m$\033[m";
          }
        }
      }
      cout << endl; //一行ぶん表示した後改行
    }
  }
};

