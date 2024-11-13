#include <iostream>
#include <conio.h>
//#include <cstdlib>
//#include <ctime>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

//22行×22列の二次元配列用領域を確保
vector<vector<int>> mapdata{};
//マップデータファイル名
static string m_filename { "2d_maze22.csv" };

enum MapObj {
  ROAD,
  WALL,
  TREASURE = 4
};

class Vector2 {
public:
  int x;
  int y;
  Vector2() = default;
  Vector2(int x, int y) : x(x), y(y) {};
};

class Player {
private:
  Vector2 Pos;
public:
  Player() : Pos(0,0) {};
  Player(int x, int y) : Pos(x, y) {};
  void setX(int x) { Pos.x = x; }
  void setY(int y) { Pos.y = y; }
  void move(int x, int y) {};
  int getX() { return Pos.x; }
  int getY() { return Pos.y; }
  void move(char key) {
    int newPosX = Pos.x;
    int newPosY = Pos.y;

    switch (key)
    {
    case 'w': // 上
      newPosY--;
      break;
    case 'a': // 左
      newPosX--;
      break;
    case 's': // 下
      newPosY++;
      break;
    case 'd': // 右
      newPosX++;
      break;
    case '@':
      exit(0);
    }

    if (newPosX >= 0 && newPosX < mapdata[0].size() && newPosY >= 0 && newPosY < mapdata.size()) //移動範囲チェック
    {
      if (mapdata[newPosY][newPosX] != WALL) {
        Pos.x = newPosX;   //移動可能ならプレイヤー位置を更新
        Pos.y = newPosY;

        if (mapdata[Pos.y][Pos.x] == TREASURE)   //プレイヤーの位置が宝箱のとき
        {
          cout << "\033[33mお宝発見！！ゲームクリア\033[m" << endl;
          exit(0);
        }
      }
    }
  }
};

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
