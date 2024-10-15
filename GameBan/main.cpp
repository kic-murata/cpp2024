#include <windows.h> //GetStdHandle関数などを使うので必要
#include <iostream>
//#include <cstdio>
#include <stdio.h>
#include <cstring>
using namespace std;

class Ban
{
  int ban[3][3], nTe; //ban[x][y]石の位置種類 nTe:何手目か
  HANDLE hOut;
  BOOL bSente; //TRUE:先手 FALSE:後手
  int Locate(int, int);
  int checkLocation(int, int);
  int bandraw();
public:
  Ban();
  int putStone();
};

Ban::Ban()
{
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      ban[i][j] = 0;
    }
  }
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  bSente = TRUE;
  nTe = 1;
  bandraw();
}

int Ban::Locate(int x, int y)
{
  COORD dwPos;
  dwPos.X = (SHORT)x;
  dwPos.Y = (SHORT)y;

  if (SetConsoleCursorPosition(hOut, dwPos) == 0)
    return -1;
  else
    return 0;
}

int Ban::putStone()
{
  char szSashite[8], szLocation[8];
  int row, col;


  while (1) {
    if (bSente)
      strcpy(szSashite, "先手");
    else
      strcpy(szSashite, "後手");
    Locate(28, 5);
    printf("  ");
    Locate(0, 5);
    printf("位置を指定してください(%s)", szSashite);
    gets(szLocation);

    if (szLocation[0] == 'A' || szLocation[0] == 'a')
      row = 0;
    else if (szLocation[0] == 'B' || szLocation[0] == 'b')
      row = 1;
    else if (szLocation[0] == 'C' || szLocation[0] == 'c')
      row = 2;
    else if (szLocation[0] == 'Q' || szLocation[0] == 'q')
      break;
    else {
      Locate(0, 6);
      printf("指定が違います");
      continue;
    }

    if (szLocation[1] == '1')
      col = 0;
    else if (szLocation[1] == '2')
      col = 1;
    else if (szLocation[1] == '3')
      col = 2;
    else {
      Locate(0, 6);
      printf("指定が違います");
      continue;
    }

    if (checkLocation(row, col) != 0) {
      Locate(0, 6);
      printf("そこには置けません!");
      continue;
    }

    if (bSente)
      ban[row][col] = 1;
    else
      ban[row][col] = 2;
    bSente = !bSente;
    bandraw();
    Locate(0, 6);
    printf("                    ");
    nTe++;
    if (nTe > 9)
      break;
  }

  return 0;
}

int Ban::checkLocation(int x, int y)
{
  if (ban[x][y] == 0)
    return 0;
  else
    return -1;
}

int Ban::bandraw()
{
  int i, j;

  Locate(0, 0);
  printf("   [１][２][３]\n");
  printf("[A]\n");
  printf("[B]\n");
  printf("[C]\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (ban[i][j] == 1) {
        Locate(j * 4 + 4, i + 1);
        printf("○");
      }
      if (ban[i][j] == 2) {
        Locate(j * 4 + 4, i + 1);
        printf("×");
      }
    }
  }
  return 0;
}

int main()
{
  Ban MyBan;
  MyBan.putStone();
  return 0;
}
