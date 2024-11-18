#include "map.h"
#include "maze2d.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;

Map::Map() = default;
void Map::Load(string filename) {
    ifstream ifs(filename);
    if (ifs.fail()) {
      cout << "FileOpen Error" << endl;
      exit(-1);
    }
    string linetext;
    int j = 0;
    //cout << j << " ";
    // ファイルの終わりまで一行ずつ読み込んでいく
    while (getline(ifs, linetext)) {
      //cout << linetext << endl;
      // 読み込んだ一行をsplit関数で分割して、vector型のstrvecへ格納する
      mapdata.resizeMap();
      istringstream iss(linetext);
      while (getline(iss, linetext, ',')) {
        mapdata.addMap(j, stoi(linetext));
      }
      j++;
    }
    ifs.close();
    //cout << "y:" << mapdata.getMapSize() << endl;
    //cout << "x:" << mapdata.getMapSize(0) << endl;
    //ofstream ofs("test.csv", ios::out);
    //if (ofs) {
    //  for (int i = 0; i < mapdata.getMapSize(); i++) {
    //    for (int j = 0; j < mapdata.getMapSize(i); j++) {
    //      ofs << mapdata.getMapValue(i, j) << ",";
    //    }
    //    ofs << endl;
    //  }
    //  ofs.close();
    //}
  }
void Map::setTreasure() {
  //cout << "start: setTreasure" << endl;
  // 乱数生成器のオブジェクトrnd_devを作成
  random_device rnd_dev{};
  // 疑似乱数（メルセンヌツイスター）のために初期シード（乱数）を与える
  mt19937 rand_engine(rnd_dev());
  // X座標用の範囲を指定した分布生成器オブジェクトrnd_xを生成
  uniform_int_distribution<int> rnd_x(2, mapdata.getMapSize(0) - 3);
  // Y座標用の範囲を指定した分布生成器オブジェクトrnd_yを生成
  uniform_int_distribution<int> rnd_y(2, mapdata.getMapSize() - 3);
  //指定範囲（2～19の範囲）で乱数を生成する
  while (1) {
    auto trX = rnd_x(rand_engine);
    auto trY = rnd_y(rand_engine);
    //cout << "trX:" << trX << " trY:" << trY << " Map:" << mapdata.getMapValue(trX, trY) << endl;
    if (mapdata.getMapValue(trX, trY) == ROAD) {//宝箱の位置が道の上にあればOK
      mapdata.setMapValue(trX, trY, TREASURE);
      break;
    }
  }
  //cout << "end: setTreasure" << endl;
}
//void Map::DrawMap(int playerX, int playerY) {
void Map::DrawMap() {
    for (int y = 0; y < mapdata.getMapSize(); y++) {
        for (int x = 0; x < mapdata.getMapSize(0); x++) {
            if (mapdata.getMapValue(x, y) == WALL) {
                cout << "#";
            }
            if (mapdata.getMapValue(x, y) == ROAD) {
                cout << ".";
            }
        }
        cout << endl;
    }
  //マップはプレイヤーの位置を中心として、5×5マスぶんだけ画面に表示
  // #####
  // # ###
  // # @
  // # ###
  // # ###
  //そのため、プレイヤーの位置からX座標、Y座標ともに２マスぶん小さい
  //ところから、２マスぶん大きい座標までの間のデータを画面に表示する
  //for (int y = playerY - 2; y <= playerY + 2; y++)
  //{
  //  for (int x = playerX - 2; x <= playerX + 2; x++)
  //  {
  //    if (x == playerX && y == playerY)   //プレイヤーのいる座標に
  //    {
  //      //cout << PLAYER;                 //プレイヤーの文字を表示
  //      cout << "@";                 //プレイヤーの文字を表示
  //    }
  //    else
  //    {
  //      //プレイヤー以外の場所を表示
  //      if (mapdata.getMapValue(x, y) == WALL) {
  //        cout << "\033[31m#\033[m";
  //      }
  //      if (mapdata.getMapValue(x, y) == ROAD) {
  //        cout << "\033[30m.\033[m";
  //      }
  //      if (mapdata.getMapValue(x, y) == TREASURE) {
  //        cout << "\033[33m$\033[m";
  //      }
  //    }
  //  }
  //  cout << endl; //一行ぶん表示した後改行
  //}
}

