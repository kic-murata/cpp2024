#include "rat.h"

int main()
{
	Rat* r1, * r2, * r3;
	r1 = new Rat(); //�P�C�ڂ̃l�Y�~�C���X�^���X�𐶐�
	r1->squeak();   //�l�Y�~�P����
	Rat::showNum(); //�l�Y�~�̑�����\���i�ÓI�����o�֐��̎��s�j
	r2 = new Rat(); //�l�Y�~2�̃C���X�^���X�𐶐�
	r3 = new Rat(); //�l�Y�~3�̃C���X�^���X�𐶐�
	r2->squeak();   //�l�Y�~2����
	r3->squeak();   //�l�Y�~3����
	Rat::showNum(); //�l�Y�~�̑�����\��
	delete r1;      //�l�Y�~1�̃C���X�^���X������
	delete r2;      //�l�Y�~2�̃C���X�^���X������
	Rat::showNum(); //�l�Y�~�̑�����\��
	delete r3;      //�l�Y�~3�̃C���X�^���X������
	Rat::showNum(); //�l�Y�~�̑�����\��
	return 0;
}