#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

//using namespace std;

std::vector<std::vector<int>> mapdata(22, std::vector<int>(22));
static std::string m_fileneme { "2d_maze22.csv" };

constexpr int WIDTH = 22;     //マップの横幅
constexpr int HEIGHT = 22;    //マップの縦幅
constexpr char PLAYER = '@';    //プレイヤーキャラの文字
constexpr char TREASURE = '$';  //宝箱の文字
constexpr char WALL = '#';      //壁の文字

char map[HEIGHT][WIDTH];    //WIDTH×HEIGHTのマップ作成(文字型配列)

int playerX, playerY;       //プレイヤーのX、Y座標
int treasureX, treasureY;   //宝箱のX,Y座標

// 文字列と区切り文字','から、CSVファイルの値を分離する関数
std::vector<std::string> split(std::string& input, char delimiter)
{
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while(std::getline(stream, field, delimiter)){
        result.push_back(field);    // 一行分の配列要素（22個）を格納したvectorを作る
    }
    // 読み取って分解した要素数を表示
    // std::cout << result.size() << std::endl;
    return result;
}

void MapdataRead(){
   // ファイルストリームを作成して、2d_maze.csvを開く
    std::ifstream ifs(m_fileneme);
    // ファイルオープンエラーチェック
    if(ifs.fail()){
        std::cout << "file open error" << std::endl;
    } else {
        std::cout << "file open success" << std::endl;
    }
    // ファイルから一行ずつ読み込むためのstring型変数lineを宣言
    std::string linetext;
    int j = 0;
    // ファイルの終わりまで一行ずつ読み込んでいく
    while(std::getline(ifs, linetext)){
        // 読み込んだ一行をsplit関数で分割して、vector型のstrvecへ格納する
        std::vector<std::string> strvec = split(linetext, ',');
        for(int i = 0; i < strvec.size(); i++){
            // std::cout << stoi(strvec.at(i));
            mapdata[j][i] = stoi(strvec.at(i));
        }
        j++;
    }
}

void InitializeMap()        //マップ内を「.」で埋める
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if(mapdata[y][x]==1){
                map[y][x] = WALL;
            } else if(mapdata[y][x]==4){
                map[y][x] = TREASURE;
            //} else if(mapdata[y][x]==2){
            //    map[y][x] = PLAYER;
            } else 
                map[y][x] = '.';
        }
    }
}

void GenerateTreasure()     //乱数で宝箱の位置を決定
{
  // 乱数生成器のオブジェクトrnd_devを作成
  std::random_device rnd_dev{};
  // 疑似乱数（メルセンヌツイスター）のために初期シード（乱数）を与える
  std::mt19937 rand_engine(rnd_dev());
  // X座標用の範囲を指定した分布生成器オブジェクトrnd_xを生成
  std::uniform_int_distribution<int> rnd_x(2, WIDTH-3);
  // Y座標用の範囲を指定した分布生成器オブジェクトrnd_yを生成
  std::uniform_int_distribution<int> rnd_y(2, HEIGHT-3);
  //指定範囲（2～47の範囲）で乱数を生成する
  treasureX = rnd_x(rand_engine);
  treasureY = rnd_y(rand_engine);
    //treasureX = rand() % (WIDTH-4);
    //treasureY = rand() % (HEIGHT-4);
    // map[treasureY+2][treasureX+2] = TREASURE;   //決定した座標のマップデータに宝箱の文字を代入
    map[treasureY][treasureX] = TREASURE;   //決定した座標のマップデータに宝箱の文字を代入
}

void DrawMap()              //マップデータの表示
{ 
    for (int y = playerY-2; y <= playerY+2; y++)
    {
        for (int x = playerX-2; x <= playerX+2; x++)
        {
            if (x == playerX && y == playerY)   //プレイヤーのいる座標に
            {
                std::cout << PLAYER;                 //プレイヤーの文字を表示
            }
            else
            {
                std::cout << map[y][x];              //プレイヤー以外の場所を表示
            }
        }
        std::cout << std::endl;                           //一行ぶん表示した後改行
    }
    // for (int y = 0; y < HEIGHT; y++)
    // {
    //     for (int x = 0; x < WIDTH; x++)
    //     {
    //         if (x == playerX && y == playerY)   //プレイヤーのいる座標に
    //         {
    //             cout << PLAYER;                 //プレイヤーの文字を表示
    //         }
    //         else
    //         {
    //             cout << map[y][x];              //プレイヤー以外の場所を表示
    //         }
    //     }
    //     cout << endl;                           //一行ぶん表示した後改行
    // }
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
    }

    if (newPlayerX >= 0 && newPlayerX < WIDTH && newPlayerY >= 0 && newPlayerY < HEIGHT) //移動範囲チェック
    {
        if(map[newPlayerY][newPlayerX]!=WALL){
            playerX = newPlayerX;   //移動可能ならプレイヤー位置を更新
            playerY = newPlayerY;

//            if (playerX == treasureX && playerY == treasureY)   //プレイヤーの位置が宝箱のとき
            if (map[playerY][playerX] == TREASURE)   //プレイヤーの位置が宝箱のとき
            {
                std::cout << "\033[31mお宝を見つけました！ゲームクリアです。\033[m" << std::endl;
                exit(0);
            }

        }
    }
}

int main()
{
    
    //srand(time(NULL));  //乱数初期化

    MapdataRead();      //CSVからのデータ読み込み
    InitializeMap();    //マップ初期化
    GenerateTreasure(); //宝箱生成

    playerX = 2;    //WIDTH / 2;    //最初の出現位置の設定（マップの真ん中）
    playerY = 2;    //HEIGHT / 2;

    system("cls");
    while (true)
    {
        //system("cls");
        // 標準出力画面のカーソル位置を(0,0)へ設定する
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });
        DrawMap();

        char input = _getch();

        MovePlayer(input);
    }

    return 0;
}
