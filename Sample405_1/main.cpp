#include "rat.h"

int main()
{
	Rat* r1, * r2, * r3; //Rat�N���X�̃|�C���^�ϐ��錾
	r1 = new Rat(); //�l�Y�~1�̃C���X�^���X����
	r1->squeak();   //�l�Y�~1����
	Rat::showNum(); //�l�Y�~�̑����̕\��
	r2 = new Rat(); //�l�Y�~2�̃C���X�^���X����
	r3 = new Rat(); //�l�Y�~3�@�@�@�@�V
	r2->squeak();   //�l�Y�~2����
	r3->squeak();   //�l�Y�~3�� �V
	Rat::showNum(); //�l�Y�~�̑����̕\��
	delete r1;      //�l�Y�~1�̃C���X�^���X����
	delete r2;      //�l�Y�~2�́@�@�@�V
	Rat::showNum(); //�l�Y�~�̑����̕\��
	delete r3;      //�l�Y�~3�̃C���X�^���X����
	Rat::showNum(); //�l�Y�~�̑����̕\��
	return 0;
}