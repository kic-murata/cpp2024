#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "map.h"
#include "player.h"
using namespace std;
int main() {
	Map map{};
	//CSV�t�@�C���̓ǂݍ��݂Ɣz��ւ̊i�[
	map.Load("2d_maze.csv"); 
	//���H��ɕ󕨂�ݒu
	map.SetTreasure();
	//�R�}���h�v�����v�g�̉�ʂɕ\������Ă�����̂�����
	Player player(2, 2);
	//Player�N���X�̃C���X�^���X�𐶐����ď����ʒu��^����
	system("cls");
	while (true) {
		//�R�}���h�v�����v�g�̉�ʂ̍�����W�i0,0�j��\���ʒu�ɂ���
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 }
		);
		//�}�b�v��`��
		map.DrawMap(player.getX(), player.getY());
		//�L�[�{�[�h����ꕶ������
		char input = _getch();
		//Player�N���X��move�֐��𕶎��ƃ}�b�v�f�[�^�������Ƃ��Ď��s
		player.move(input, map.mapdata);
	}
	return 0;
}