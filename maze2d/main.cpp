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

//22�s�~22��̓񎟌��z��p�̈���m��
vector<vector<int>> mapdata{};
//vector<vector<int>> mapdata(22, vector<int>(22));
//�}�b�v�f�[�^�t�@�C����
static string m_fileneme { "2d_maze22.csv" };

constexpr int WIDTH = 22;     //�}�b�v�̉���
constexpr int HEIGHT = 22;    //�}�b�v�̏c��
constexpr char PLAYER = '@';    //�v���C���[�L�����̕���
constexpr char TREASURE = '$';  //�󔠂̕���
constexpr char WALL = '#';      //�ǂ̕���

char map[HEIGHT][WIDTH];    //WIDTH�~HEIGHT�̃}�b�v�쐬(�����^�z��)

int playerX, playerY;       //�v���C���[��X�AY���W
int treasureX, treasureY;   //�󔠂�X,Y���W

class Player {
private:
    int x, y;
};

class Treasure {
private:
    int x, y;
};

// ������Ƌ�؂蕶��','����ACSV�t�@�C���̒l�𕪗�����֐�
vector<string> split(string& input, char delimiter)
{
    istringstream stream(input);
    string field;                   // ��s���܂�܂�ǂݍ��񂾃f�[�^���i�[���镶����
    vector<string> result;          // �J���}�ŋ�؂������ڂ��i�[����z��
    while(getline(stream, field, delimiter)){
        result.push_back(field);    // ��s���̔z��v�f�i22�j���i�[����vector�����
    }
    // �ǂݎ���ĕ��������v�f����\��
    // cout << result.size() << endl;
    return result;
}

void MapdataRead(){

   // �t�@�C���X�g���[�����쐬���āA2d_maze.csv���J��
    ifstream ifs(m_fileneme);
    // �t�@�C���I�[�v���G���[�`�F�b�N
    if(ifs.fail()){
        cout << "file open error" << endl;
    } else {
        cout << "file open success" << endl;
    }
    // �t�@�C�������s���ǂݍ��ނ��߂�string�^�ϐ�line��錾
    string linetext;
    int j = 0;
    // �t�@�C���̏I���܂ň�s���ǂݍ���ł���
    while(getline(ifs, linetext)){
        // �ǂݍ��񂾈�s��split�֐��ŕ������āAvector�^��strvec�֊i�[����
        vector<string> strvec = split(linetext, ',');
        cout << "strvec.size:" << strvec.size() << endl;
        cout << "mapdata.size:" << mapdata.size() << endl;
        mapdata.resize(mapdata.size() + 1);
//        mapdata.emplace_back(strvec);
//        mapdata.push_back(strvec);
        cout << "mapdata.size:" << mapdata.size() << endl;
        for(int i = 0; i < strvec.size(); i++){
            // cout << stoi(strvec.at(i));
            //mapdata[j][i] = stoi(strvec.at(i));
            mapdata.push_back(stoi(strvec.at(i)));
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
  random_device rnd_dev{};
  // �^�������i�����Z���k�c�C�X�^�[�j�̂��߂ɏ����V�[�h�i�����j��^����
  mt19937 rand_engine(rnd_dev());
  // X���W�p�͈̔͂��w�肵�����z������I�u�W�F�N�grnd_x�𐶐�
  uniform_int_distribution<int> rnd_x(2, WIDTH-3);
  // Y���W�p�͈̔͂��w�肵�����z������I�u�W�F�N�grnd_y�𐶐�
  uniform_int_distribution<int> rnd_y(2, HEIGHT-3);
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
    //�}�b�v�̓v���C���[�̈ʒu�𒆐S�Ƃ��āA5�~5�}�X�Ԃ񂾂���ʂɕ\��
    // #####
    // # ###
    // # @
    // # ###
    // # ###
    //���̂��߁A�v���C���[�̈ʒu����X���W�AY���W�Ƃ��ɂQ�}�X�Ԃ񏬂���
    //�Ƃ��납��A�Q�}�X�Ԃ�傫�����W�܂ł̊Ԃ̃f�[�^����ʂɕ\������
    for (int y = playerY-2; y <= playerY+2; y++)
    {
        for (int x = playerX-2; x <= playerX+2; x++)
        {
            if (x == playerX && y == playerY)   //�v���C���[�̂�����W��
            {
                cout << PLAYER;                 //�v���C���[�̕�����\��
            }
            else
            {
                cout << map[y][x];              //�v���C���[�ȊO�̏ꏊ��\��
            }
        }
        cout << endl;                           //��s�Ԃ�\����������s
    }
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
        case '@':
            exit(0);
    }

    if (newPlayerX >= 0 && newPlayerX < WIDTH && newPlayerY >= 0 && newPlayerY < HEIGHT) //�ړ��͈̓`�F�b�N
    {
        if(map[newPlayerY][newPlayerX]!=WALL){
            playerX = newPlayerX;   //�ړ��\�Ȃ�v���C���[�ʒu���X�V
            playerY = newPlayerY;

            if (map[playerY][playerX] == TREASURE)   //�v���C���[�̈ʒu���󔠂̂Ƃ�
            {
                cout << "\033[31m����������܂����I�Q�[���N���A�ł��B\033[m" << endl;
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

    playerX = 2;    //�v���C���[�̏o���ʒu�̐ݒ�
    playerY = 2;    //(X,Y) = (2,2)

    //system("cls");  //�R�}���h�v�����v�g�̉�ʏ���
    while (true)
    {
        // �W���o�͉�ʂ̃J�[�\���ʒu��(0,0)�֐ݒ肷��
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { 0, 0 });
        DrawMap();

        char input = _getch();

        MovePlayer(input);
    }

    return 0;
}
