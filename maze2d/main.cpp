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

constexpr int WIDTH = 22;     //�}�b�v�̉���
constexpr int HEIGHT = 22;    //�}�b�v�̏c��
constexpr char PLAYER = '@';    //�v���C���[�L�����̕���
constexpr char TREASURE = '$';  //�󔠂̕���
constexpr char WALL = '#';      //�ǂ̕���

char map[HEIGHT][WIDTH];    //WIDTH�~HEIGHT�̃}�b�v�쐬(�����^�z��)

int playerX, playerY;       //�v���C���[��X�AY���W
int treasureX, treasureY;   //�󔠂�X,Y���W

// ������Ƌ�؂蕶��','����ACSV�t�@�C���̒l�𕪗�����֐�
std::vector<std::string> split(std::string& input, char delimiter)
{
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while(std::getline(stream, field, delimiter)){
        result.push_back(field);    // ��s���̔z��v�f�i22�j���i�[����vector�����
    }
    // �ǂݎ���ĕ��������v�f����\��
    // std::cout << result.size() << std::endl;
    return result;
}

void MapdataRead(){
   // �t�@�C���X�g���[�����쐬���āA2d_maze.csv���J��
    std::ifstream ifs(m_fileneme);
    // �t�@�C���I�[�v���G���[�`�F�b�N
    if(ifs.fail()){
        std::cout << "file open error" << std::endl;
    } else {
        std::cout << "file open success" << std::endl;
    }
    // �t�@�C�������s���ǂݍ��ނ��߂�string�^�ϐ�line��錾
    std::string linetext;
    int j = 0;
    // �t�@�C���̏I���܂ň�s���ǂݍ���ł���
    while(std::getline(ifs, linetext)){
        // �ǂݍ��񂾈�s��split�֐��ŕ������āAvector�^��strvec�֊i�[����
        std::vector<std::string> strvec = split(linetext, ',');
        for(int i = 0; i < strvec.size(); i++){
            // std::cout << stoi(strvec.at(i));
            mapdata[j][i] = stoi(strvec.at(i));
        }
        j++;
    }
}

void InitializeMap()        //�}�b�v�����u.�v�Ŗ��߂�
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

void GenerateTreasure()     //�����ŕ󔠂̈ʒu������
{
  // ����������̃I�u�W�F�N�grnd_dev���쐬
  std::random_device rnd_dev{};
  // �^�������i�����Z���k�c�C�X�^�[�j�̂��߂ɏ����V�[�h�i�����j��^����
  std::mt19937 rand_engine(rnd_dev());
  // X���W�p�͈̔͂��w�肵�����z������I�u�W�F�N�grnd_x�𐶐�
  std::uniform_int_distribution<int> rnd_x(2, WIDTH-3);
  // Y���W�p�͈̔͂��w�肵�����z������I�u�W�F�N�grnd_y�𐶐�
  std::uniform_int_distribution<int> rnd_y(2, HEIGHT-3);
  //�w��͈́i2�`47�͈̔́j�ŗ����𐶐�����
  treasureX = rnd_x(rand_engine);
  treasureY = rnd_y(rand_engine);
    //treasureX = rand() % (WIDTH-4);
    //treasureY = rand() % (HEIGHT-4);
    // map[treasureY+2][treasureX+2] = TREASURE;   //���肵�����W�̃}�b�v�f�[�^�ɕ󔠂̕�������
    map[treasureY][treasureX] = TREASURE;   //���肵�����W�̃}�b�v�f�[�^�ɕ󔠂̕�������
}

void DrawMap()              //�}�b�v�f�[�^�̕\��
{ 
    for (int y = playerY-2; y <= playerY+2; y++)
    {
        for (int x = playerX-2; x <= playerX+2; x++)
        {
            if (x == playerX && y == playerY)   //�v���C���[�̂�����W��
            {
                std::cout << PLAYER;                 //�v���C���[�̕�����\��
            }
            else
            {
                std::cout << map[y][x];              //�v���C���[�ȊO�̏ꏊ��\��
            }
        }
        std::cout << std::endl;                           //��s�Ԃ�\����������s
    }
    // for (int y = 0; y < HEIGHT; y++)
    // {
    //     for (int x = 0; x < WIDTH; x++)
    //     {
    //         if (x == playerX && y == playerY)   //�v���C���[�̂�����W��
    //         {
    //             cout << PLAYER;                 //�v���C���[�̕�����\��
    //         }
    //         else
    //         {
    //             cout << map[y][x];              //�v���C���[�ȊO�̏ꏊ��\��
    //         }
    //     }
    //     cout << endl;                           //��s�Ԃ�\����������s
    // }
}

void MovePlayer(char direction)                 //���͂��ꂽ�����ɂ��v���C���[�̈ړ�����
{
    int newPlayerX = playerX;
    int newPlayerY = playerY;

    switch (direction)
    {
        case 'w': // ��
            newPlayerY--;
            break;
        case 'a': // ��
            newPlayerX--;
            break;
        case 's': // ��
            newPlayerY++;
            break;
        case 'd': // �E
            newPlayerX++;
            break;
    }

    if (newPlayerX >= 0 && newPlayerX < WIDTH && newPlayerY >= 0 && newPlayerY < HEIGHT) //�ړ��͈̓`�F�b�N
    {
        if(map[newPlayerY][newPlayerX]!=WALL){
            playerX = newPlayerX;   //�ړ��\�Ȃ�v���C���[�ʒu���X�V
            playerY = newPlayerY;

//            if (playerX == treasureX && playerY == treasureY)   //�v���C���[�̈ʒu���󔠂̂Ƃ�
            if (map[playerY][playerX] == TREASURE)   //�v���C���[�̈ʒu���󔠂̂Ƃ�
            {
                std::cout << "\033[31m����������܂����I�Q�[���N���A�ł��B\033[m" << std::endl;
                exit(0);
            }

        }
    }
}

int main()
{
    
    //srand(time(NULL));  //����������

    MapdataRead();      //CSV����̃f�[�^�ǂݍ���
    InitializeMap();    //�}�b�v������
    GenerateTreasure(); //�󔠐���

    playerX = 2;    //WIDTH / 2;    //�ŏ��̏o���ʒu�̐ݒ�i�}�b�v�̐^�񒆁j
    playerY = 2;    //HEIGHT / 2;

    system("cls");
    while (true)
    {
        //system("cls");
        // �W���o�͉�ʂ̃J�[�\���ʒu��(0,0)�֐ݒ肷��
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });
        DrawMap();

        char input = _getch();

        MovePlayer(input);
    }

    return 0;
}
