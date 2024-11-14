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

enum class MapObj {
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
  Player() : m_x(0), m_y(0) {};
  Player(int x, int y) : m_x(x), m_y(y) {};
  void setX(int x) { m_x = x; }
  void setY(int y) { m_y = y; }
  void move(int x, int y) {};
};

class Map {
//private:
//  Vector2 TrPos;
public:
  //Map() : TrPos(0,0) {};
  //void setTrPos(int x, int y) {
  //  TrPos.x = x;
  //  TrPos.y = y;
  //}
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
    if (mapdata[trY][trX] == static_cast<int>(MapObj::ROAD)) {
      mapdata[trY][trY] = static_cast<int>(MapObj::TREASURE);
    }
    else
    { //壁の中に宝箱が設定されたらもう一度やり直し
      setTreasure();
    }
  }
};

//// 文字列と区切り文字','から、CSVファイルの値を分離する関数
//vector<int> split(string& input, char delimiter)
//{
//    istringstream stream(input);
//    string field;                   // 一行分まるまる読み込んだデータを格納する文字列
//    vector<int> result;          // カンマで区切った項目を格納する配列
//    while(getline(stream, field, delimiter)){
//        result.push_back(stoi(field));    // 一行分の配列要素（22個）を格納したvectorを作る
//    }
//    return result;
//}

//void MapdataRead(){
//
//    // ファイルストリームを作成して、2d_maze.csvを開く
//    ifstream ifs(m_fileneme);
//    // ファイルオープンエラーチェック
//    if(ifs.fail()){
//        cout << "file open error" << endl;
//    } else {
//        cout << "file open success" << endl;
//    }
//    // ファイルから一行ずつ読み込むためのstring型変数lineを宣言
//    string linetext;
//    int j = 0;
//    // ファイルの終わりまで一行ずつ読み込んでいく
//    while(getline(ifs, linetext)){
//        // 読み込んだ一行をsplit関数で分割して、vector型のstrvecへ格納する
//        vector<int> strvec = split(linetext, ',');
//        mapdata.resize(mapdata.size() + 1);
//        for(int i = 0; i < strvec.size(); i++){
//            mapdata[j].push_back(strvec.at(i));
//        }
//        j++;
//    }
//}

//void InitializeMap()        //マップ内を「.」で埋める
//{
//    for (int y = 0; y < HEIGHT; y++)
//    {
//        for (int x = 0; x < WIDTH; x++)
//        {
//            if(mapdata[y][x]==1){
//                map[y][x] = WALL;
//            } else if(mapdata[y][x]==4){
//                map[y][x] = TREASURE;
//            //} else if(mapdata[y][x]==2){
//            //    map[y][x] = PLAYER;
//            } else 
//                map[y][x] = '.';
//        }
//    }
//}

//void GenerateTreasure()     //乱数で宝箱の位置を決定
//{
//  // 乱数生成器のオブジェクトrnd_devを作成
//  random_device rnd_dev{};
//  // 疑似乱数（メルセンヌツイスター）のために初期シード（乱数）を与える
//  mt19937 rand_engine(rnd_dev());
//  // X座標用の範囲を指定した分布生成器オブジェクトrnd_xを生成
//  uniform_int_distribution<int> rnd_x(2, WIDTH-3);
//  // Y座標用の範囲を指定した分布生成器オブジェクトrnd_yを生成
//  uniform_int_distribution<int> rnd_y(2, HEIGHT-3);
//  //指定範囲（2～47の範囲）で乱数を生成する
//  treasureX = rnd_x(rand_engine);
//  treasureY = rnd_y(rand_engine);
//  mapdata[treasureY][treasureX] = static_cast<int>(MapObj::TREASURE);   //決定した座標のマップデータに宝箱の文字を代入
//}

void DrawMap()              //マップデータの表示
{ 
    //マップはプレイヤーの位置を中心として、5×5マスぶんだけ画面に表示
    // #####
    // # ###
    // # @
    // # ###
    // # ###
    //そのため、プレイヤーの位置からX座標、Y座標ともに２マスぶん小さい
    //ところから、２マスぶん大きい座標までの間のデータを画面に表示する
    for (int y = playerY-2; y <= playerY+2; y++)
    {
        for (int x = playerX-2; x <= playerX+2; x++)
        {
            if (x == playerX && y == playerY)   //プレイヤーのいる座標に
            {
                //cout << PLAYER;                 //プレイヤーの文字を表示
              cout << "@";                 //プレイヤーの文字を表示
            }
            else
            {
                //cout << map[y][x];              //プレイヤー以外の場所を表示
              if (mapdata[y][x] == static_cast<int>(MapObj::WALL)) cout << "\033[31m#\033[m";
              if (mapdata[y][x] == static_cast<int>(MapObj::ROAD)) cout << "\033[30m.\033[m";
              if (mapdata[y][x] == static_cast<int>(MapObj::TREASURE)) cout << "\033[33m$\033[m";

            }
        }
        cout << endl;                           //一行ぶん表示した後改行
    }
}

void MovePlayer(char direction)                 //入力された文字によるプレイヤーの移動処理
{
    int newPlayerX = playerX;
    int newPlayerY = playerY;

    switch (direction)
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
        if(mapdata[newPlayerY][newPlayerX]!= static_cast<int>(MapObj::WALL)){
            playerX = newPlayerX;   //移動可能ならプレイヤー位置を更新
            playerY = newPlayerY;

            if (mapdata[playerY][playerX] == static_cast<int>(MapObj::TREASURE))   //プレイヤーの位置が宝箱のとき
            {
                cout << "\033[33mお宝を見つけました！ゲームクリアです。\033[m" << endl;
                exit(0);
            }
        }
    }
}

int main()
{
  Map map;
  map.Load("2d_maze22.csv");
  map.setTreasure();
    //MapdataRead();      //CSVからのデータ読み込み
    //InitializeMap();    //マップ初期化
    //GenerateTreasure(); //宝箱生成

    playerX = 2;    //プレイヤーの出現位置の設定
    playerY = 2;    //(X,Y) = (2,2)

    //system("cls");  //コマンドプロンプトの画面消去
    while (true)
    {
        // 標準出力画面のカーソル位置を(0,0)へ設定する
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });
        DrawMap();

        char input = _getch();

        MovePlayer(input);
    }

    return 0;
}
