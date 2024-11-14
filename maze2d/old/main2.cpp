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
static string m_fileneme { "2d_maze22.csv" };

constexpr int WIDTH = 22;     //マップの横幅
constexpr int HEIGHT = 22;    //マップの縦幅
//constexpr char PLAYER = '@';    //プレイヤーキャラの文字
//constexpr char TREASURE = '$';  //宝箱の文字
//constexpr char WALL = 'ﾛ';      //壁の文字

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

//char map[HEIGHT][WIDTH];    //WIDTH×HEIGHTのマップ作成(文字型配列)

int playerX, playerY;       //プレイヤーのX、Y座標
int treasureX, treasureY;   //宝箱のX,Y座標

class Player {
private:
  int m_x, m_y;
public:
  Vector2 PlayerPos;
  Player() : PlayerPos(0,0) {};
  Player(int x, int y) : PlayerPos(x, y) {};
  void setX(int x) { PlayerPos.x = x; }
  void setY(int y) { PlayerPos.y = y; }
  void move(int x, int y) {};
  int getX() { return PlayerPos.x; }
  int getY() { return PlayerPos.y; }
  //Player() : m_x(0), m_y(0) {};
  //Player(int x, int y) : m_x(x), m_y(y) {};
  //void setX(int x) { m_x = x; }
  //void setY(int y) { m_y = y; }
  //void move(int x, int y) {};
  //int getX() { return m_x; }
  //int getY() { return m_y; }
  void move(char key) {
    int newPlayerX = playerX;
    int newPlayerY = playerY;

    switch (key)
    {
    case 'w': // 上
      newPlayerY--;
      break;
    case 'a': // 左
      newPlayerX--;
      break;
    case 's': // 下
      newPlayerY++;
      break;
    case 'd': // 右
      newPlayerX++;
      break;
    case '@':
      exit(0);
    }

    if (newPlayerX >= 0 && newPlayerX < WIDTH && newPlayerY >= 0 && newPlayerY < HEIGHT) //移動範囲チェック
    {
      if (mapdata[newPlayerY][newPlayerX] != WALL) {
        playerX = newPlayerX;   //移動可能ならプレイヤー位置を更新
        playerY = newPlayerY;

        if (mapdata[playerY][playerX] == TREASURE)   //プレイヤーの位置が宝箱のとき
        {
          cout << "\033[33mお宝を見つけました！ゲームクリアです。\033[m" << endl;
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
    if (mapdata[trY][trX] == ROAD) {
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
          //cout << map[y][x];              //プレイヤー以外の場所を表示
          if (mapdata[y][x] == WALL) cout << "\033[31m#\033[m";
          if (mapdata[y][x] == ROAD) cout << "\033[30m.\033[m";
          if (mapdata[y][x] == TREASURE) cout << "\033[33m$\033[m";

        }
      }
      cout << endl;                           //一行ぶん表示した後改行
    }
  }
};

//void DrawMap()              //マップデータの表示
//{ 
//    //マップはプレイヤーの位置を中心として、5×5マスぶんだけ画面に表示
//    // #####
//    // # ###
//    // # @
//    // # ###
//    // # ###
//    //そのため、プレイヤーの位置からX座標、Y座標ともに２マスぶん小さい
//    //ところから、２マスぶん大きい座標までの間のデータを画面に表示する
//    for (int y = playerY-2; y <= playerY+2; y++)
//    {
//        for (int x = playerX-2; x <= playerX+2; x++)
//        {
//            if (x == playerX && y == playerY)   //プレイヤーのいる座標に
//            {
//                //cout << PLAYER;                 //プレイヤーの文字を表示
//              cout << "@";                 //プレイヤーの文字を表示
//            }
//            else
//            {
//                //cout << map[y][x];              //プレイヤー以外の場所を表示
//              if (mapdata[y][x] == WALL) cout << "\033[31m#\033[m";
//              if (mapdata[y][x] == ROAD) cout << "\033[30m.\033[m";
//              if (mapdata[y][x] == TREASURE) cout << "\033[33m$\033[m";
//
//            }
//        }
//        cout << endl;                           //一行ぶん表示した後改行
//    }
//}

//void MovePlayer(char direction)                 //入力された文字によるプレイヤーの移動処理
//{
//    int newPlayerX = playerX;
//    int newPlayerY = playerY;
//
//    switch (direction)
//    {
//        case 'w': // 上
//            newPlayerY--;
//            break;
//        case 'a': // 左
//            newPlayerX--;
//            break;
//        case 's': // 下
//            newPlayerY++;
//            break;
//        case 'd': // 右
//            newPlayerX++;
//            break;
//        case '@':
//            exit(0);
//    }
//
//    if (newPlayerX >= 0 && newPlayerX < WIDTH && newPlayerY >= 0 && newPlayerY < HEIGHT) //移動範囲チェック
//    {
//        if(mapdata[newPlayerY][newPlayerX]!= WALL){
//            playerX = newPlayerX;   //移動可能ならプレイヤー位置を更新
//            playerY = newPlayerY;
//
//            if (mapdata[playerY][playerX] == TREASURE)   //プレイヤーの位置が宝箱のとき
//            {
//                cout << "\033[33mお宝を見つけました！ゲームクリアです。\033[m" << endl;
//                exit(0);
//            }
//        }
//    }
//}

int main()
{
  Map map;
  //CSVからのデータ読み込み&マップデータの格納
  map.Load("2d_maze22.csv");
  //宝箱の生成
  map.setTreasure();

  Player player;
    playerX = 2;    //プレイヤーの出現位置の設定
    playerY = 2;    //(X,Y) = (2,2)

    //system("cls");  //コマンドプロンプトの画面消去
    while (true)
    {
        // 標準出力画面のカーソル位置を(0,0)へ設定する
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });
        //DrawMap();
        map.DrawMap(playerX, playerY);

        char input = _getch();

        player.move(input);
        //MovePlayer(input);
    }

    return 0;
}
