#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
using namespace std;
int main() {
	Map map{};
	//CSV�t�@�C���̓ǂݍ��݂Ɣz��ւ̊i�[
	map.Load("2d_maze.csv"); 
	//�}�b�v�f�[�^��ɕ󕨂̃f�[�^���i�[
	map.SetTreasure();
	//�R�}���h�v�����v�g�̉�ʂɕ\������Ă�����̂�����
	system("cls");
	//�R�}���h�v�����v�g�̉�ʂ̍�����W�i0,0�j��\���ʒu�ɂ���
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
	);
	//�}�b�v��`��
	map.DrawMap(10,10);
	return 0;
}