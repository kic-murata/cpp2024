#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map;                //Map�N���X�̃C���X�^���X����
	map.Load("2d_maze.csv");//���H�f�[�^�̓ǂݍ��݂Ɣz��ւ̊i�[
	map.SetTreasure();      //�󕨂𐶐�
	system("cls");          //��ʃN���A
	//�R�}���h�v�����v�g�̃E�C���h�E���w�肵�āA�\���ʒu��(0,0)�֐ݒ�
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
	map.DrawMap(10,5);          //�}�b�v���R�}���h�v�����v�g�֕`��
	return 0;
}