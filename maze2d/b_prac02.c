#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 4  //�X�L����
#define Mob_Num 3   //�G�̐�
#define File_Num 3  //�f�[�^�t�@�C����
//��������������UINT�ōĒ�`
typedef unsigned int UINT;

typedef struct { //Skill�^�\����
	char name[20]; //�X�L����
	int type;      //�X�L���̎�ށi0: HP��, 1: AtkUp, 2: ��Ԉُ�񕜁j
	int use_mp;    //�g�pMP��
	int effect;    //�X�L������
} Skill;
typedef struct { //Spec�^�\����
	char name[20]; //���O
	int hp;        //HP
	int atk;       //�U����
	int def;       //�h���
	UINT state;    //���
} Spec;
typedef struct { //Chara�^�\����
	Spec sp;       //Spec�^�\���̕ϐ�
	int maxhp;     //�ő�HP
	int mp;        //MP
	Skill skl[Skil_Num]; //Skill�^�\���̔z��
} Chara;
typedef struct { //Mob�^�\����
	Spec sp;       //Spec�^�\���̕ϐ�
	int rate;      //��Ԉُ�U���������[�g%�\�L
} Mob;

//�񋓌^BitState�̐錾
enum BitState
{
	//�ʏ���
	Base = 0,            //0000 0000 0000 0000
	//(1���炢�����ɃV�t�g���邩)
	Poison = 1 << 0,     //(  1)0000 0000 0000 0001(��)
	Sleep = 1 << 1,      //(  2)0000 0000 0000 0010(����)
	Paralysis = 1 << 2,  //(  4)0000 0000 0000 0100(���)
	Burn = 1 << 3,       //(  8)0000 0000 0000 1000(�Ώ�)Up)
	AtkDown = 1 << 5,    //( 32)0000 0000 0010 0000(�U����Down)
	Dead = 1 << 6,       //( 64)0000 0000 0100 0000(���S�t���O)
  Atk_Skill = 1 << 7,  //(128)0000 0000 1000 0000
                       //(���̃t���O��ON�̂ݏ�Ԉُ��t���\�j
	AtkUp = 1 << 8,      //0000 0001 0000 0000(�U����Up)
	DefUp = 1 << 9,      //0000 0010 0000 0000(�h���Up�j
	DeBuff = 0xff        //0000 0000 1111 1111(�f�o�t�����p)
};

//�o�߃^�[��(�����F���L�����U���^�[���A��F�G�L�����U���^�[��)
int TurnCount = 0;

//��Ԃ�\������֐�
void DisplayStatus(Chara c);

//�퓬���[�h�ֈڍs����֐�
void BattleMode(Chara* c, Mob m);
//�퓬���̃��j���[�\�����s��
int DisplayMenu(void);
//�X�L���g�p���̃��j���[�\�����s��
int SkillMenu(Chara c);
//�U�����Ɩh�䑤�̃p�����[�^���g�����U���_���[�W�v�Z
int DamageCalc(Spec sp1, Spec sp2);
//�퓬���[�h����HP�v�Z�Ǝ��S����
void BattleMessage(Spec sp1, Spec* sp2);
//�f�[�^�t�@�C����ǂݍ���Œl��ݒ肷��
int LoadDataFile(char* filename[], Chara* c, Mob* m);

/* b_prac01.exe [����:0~Mob_Num-1]
* [����:0~Mob_Num-1]��0����Mob_Num-1�܂ł̐������w�肵�Ď��s���邱�Ƃ�
* �o�ꂷ��G�̎�ނ��w��ł���B�ȗ������ꍇ��0~Mob_Num-1�̗����ƂȂ� */
main(int argc, char* argv[])
{
	//������i�V�[�h�j�̏�����
	srand(time(0));
	//���L�����ƓG�L�����̃p�����[�^�ݒ�
	Chara chara;
	Mob mob[Mob_Num];
	//�g�p����f�[�^�t�@�C�����X�g
	char* DataFile[] = { "chara.csv","skill.csv","mob.csv" };
	//�f�[�^�ǂݍ��݂̌��ʂ��i�[����ϐ���錾
	int result;
	//LoadDataFile�֐��̌Ăяo���Ɩ߂�l�̊i�[
	result = LoadDataFile(DataFile, &chara, mob);
	//�߂�l��-1�������Ƃ�
	if (result == -1) {
		printf("�v���I�ȃG���[���������܂���\n");
		//main�֐���return���ŋ����I�ɏI������
		return;
	}

	//������0~Mob_Num-1�̐��l�����߂�
	int num = rand() % Mob_Num;
	//���s���ɃR�}���h���C���������������ꍇ
	if (argc > 1) {
		//�����𐔒l�ɕϊ�
		num = atoi(argv[1]);
		//�����̐��l��0~Mob_Num-1�͈̔͂ɂȂ����
		if (num < 0 || num >= Mob_Num) {
			//�����𐶐�
			num = rand() % Mob_Num;
		}
	}
	//�퓬���[�h���J�n
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%s�̎��S�ɂ��Q�[���I�[�o�[\n", chara.sp.name);
	}
}
/*int DamageCalc(Spec sp1, Spec sp2)
* �^�_���v�Z�֐�
* ��1�����FSpec�^�\���̕ϐ��i�U�����j
* ��2�����FSpec�^�\���̕ϐ��i�h�䑤�j
* �i�^�_���j���U����Atk�~(�U����Atk���h�䑤Def�j�{�U����Atk�~����0~0.5
*/
int DamageCalc(Spec sp1, Spec sp2) {
	int damage;
	//�U���̓_�E���t���O��ON�ŁAAtk_Skill��OFF�̂Ƃ��i���L�����݂̂��̏����ɊY���j
	if ((sp1.state & AtkDown) && !(sp1.state & Atk_Skill)) {
		//�U���͂�0.8�{�ɂ��ă_���[�W�v�Z
		sp1.atk *= 0.8;
	}
	damage = sp1.atk * ((float)sp1.atk / sp2.def)
		+ sp1.atk * (rand() % 50) / 100.0;
	//100����1�̊m���ŉ�S/�ɍ��̈ꌂ
	if (rand() % 100 == 99) {
		return 2 * damage;  //�_���[�W��2�{
	}
	return damage;  //�ʏ�_���[�W
}
/*void BattleMessage(Spec sp1, Spec* sp2)
* �퓬���[�h���̃��b�Z�[�W�\�����s��
* ��1�����FSpec�^�\���̕ϐ��i�U�����j
* ��2�����FSpec�^�\���̕ϐ��̃A�h���X�i�h�䑤�j
*/
void BattleMessage(Spec sp1, Spec* sp2) {
	//��_�����i�[����ϐ�
	int damage;
	//�^�[�����ЂƂi�߂Ă���
	TurnCount++;
	//�U������\��
	printf("%s�̍U��\n", sp1.name);
	//�_���[�W�v�Z
	damage = DamageCalc(sp1, *sp2);
	//��_���̕\��
	printf("%s��%d�̃_���[�W\n\n", sp2->name, damage);
	//�h�䑤����_���[�W����HP�����Z
	sp2->hp -= damage;
	//HP���O�ȉ��ɂȂ�����
	if (sp2->hp <= 0) {
		//�h�䑤���|���ꂽ�Ƃ������b�Z�[�W��\��
		printf("%s�͓|���ꂽ\n", sp2->name);
		//�h�䑤�Ɏ��S�t���O�𗧂Ă�
		sp2->state |= Dead;
	}
}
/*void BattleMode(Chara* c, Mob m)
* �퓬���[�h���̃��b�Z�[�W�\�����s��
* ��1�����FChara�^�\���̕ϐ��̃A�h���X�i���L�����j
* ��2�����FMob�^�\���̕ϐ��i�G�L�����j
*/
void BattleMode(Chara* c, Mob m) {
#define Poison_Damage 0.8 //�ŏ�Ԃ̂Ƃ��̖��^�[��������
#define Burn_Damage 0.9   //�Ώ���Ԃ̂Ƃ��̖��^�[��������
//	static const float Burn_Damage = 0.9;
	int command, skill;
	system("cls");      //�R�}���h�v�����v�g��cls���߂̎��s
	DisplayStatus(*c);
	printf("%s�������ꂽ�I\n", m.sp.name);
	while (1) {
		command = DisplayMenu();

		//��Ԉُ�̂Ƃ���HP��MP�̏���
		if (c->sp.state & Poison) { //�ł̃t���O��ON�̂Ƃ� 
			c->sp.hp *= Poison_Damage;//���L����HP��Poison_Damage(0.8)�{�ɂ���
		}
		if (c->sp.state & Burn) {   //�Ώ��̃t���O��ON�̂Ƃ�
			c->sp.hp *= Burn_Damage;  //���L������HP��Burn_Damage(0.9)�{�ɂ���
			c->mp *= Burn_Damage;     //���L������MP��Burn_Damage(0.9)�{�ɂ���
		}
		//[��������]
		if (command == 1) {
			DisplayStatus(*c);
			//TurnCount�������̂Ƃ��͎��L�����̍U��
			if (TurnCount % 2 == 0) {
				//�퓬���b�Z�[�W�̕\���Ɩh�䑤HP���Z�A���S�`�F�b�N
				BattleMessage(c->sp, &m.sp);
				//�G�L�����̎��S�t���O��ON�Ȃ�
				if (m.sp.state & Dead) {
					break;
				}
			}
			//TurnCount����̂Ƃ��͓G�̍U��
			if (TurnCount % 2 == 1) {
				//�퓬���b�Z�[�W�̕\���Ɩh�䑤HP���Z�A���S�`�F�b�N
				BattleMessage(m.sp, &c->sp);
				//���L�����̎��S�t���O��ON�Ȃ�
				if (c->sp.state & Dead) {
					break;
				}
				else { //���L����������ł��Ȃ���Έȉ��̏��������s
					//��Ԉُ�t���m���̌v�Z
					if (rand() % 100 < m.rate) {
						printf("��Ԉُ�U�����󂯂��I\n");
						//���L�����ɏ�Ԉُ��t������Ƃ��ɂ́AAtk_Skill�t���O���������Ă���
						c->sp.state |= (m.sp.state & ~Atk_Skill);
					}
					DisplayStatus(*c);
				}
			}
		}
		//DisplayMenu�ŋ����I���p�̃L�[�������ꂽ�Ƃ��̏���
		else if (command == -1) {
			c->sp.state |= Dead;  //���L�����̎��S�t���O��ON
			return;               //�֐��𔲂��o��
		}
		//[�X�L��]
		else if (command == 2) {
			printf("�X�L���̑I��\n");
			skill = SkillMenu(*c);  //skill��0~2�̂����ꂩ
			//MP�c�ʃ`�F�b�N�i��MP�ʂ��X�L���g�pMP�ʂ�葽���Ƃ��j
			if (c->mp >= c->skl[skill].use_mp) {
				//���L������MP���g�p�����Ԃ񌸂炷
				c->mp -= c->skl[skill].use_mp;
				//�X�L����type�l�ɂ���ĕ��򏈗�
				switch (c->skl[skill].type) {
				case 0:  //HP�񕜃X�L���g�p���̏���
					//���L����HP�ɃX�L���g�p�ɂ��񕜗�(effect�l�j�����Z
					c->sp.hp += c->skl[skill].effect;
					//���L����HP��MAXHP�𒴂�����AMAXHP�ɑ�����
					if (c->sp.hp > c->maxhp) { c->sp.hp = c->maxhp; }
					printf("HP��%d�񕜂���!\n", c->skl[skill].effect);
					break;
				case 1: //�U���̓A�b�v�̏���
					//���L����ATK��1.20�{�i��120��100�j
					c->sp.atk *= c->skl[skill].effect / 100.0;
					//�U���̓A�b�v�t���OON
					c->sp.state |= AtkUp;
					printf("�U���͂��A�b�v����!\n");
					break;
				case 2: //��Ԉُ�񕜂̏���
					//�f�o�t�n����8�r�b�g������0�ɂ���r�b�g��(~DeBuff)��AND���Z
					c->sp.state &= ~DeBuff;
					printf("��Ԉُ킪�񕜂���!\n");
					break;
				case 3:  //�h��̓A�b�v�̏���
					//���L������Def�l��1.5�{�i150��100.0�j�ɂ���
					c->sp.def *= c->skl[skill].effect / 100.0;
					//DefUp�t���O�𗧂Ă�
					c->sp.state |= DefUp;
					//�����A�b�v����������ʕ\��
					printf("�h��͂��A�b�v�����I\n");
					break;
				default:
					break;
				}
				//���L�����̃X�e�[�^�X�̒l����ʕ\��
				DisplayStatus(*c);
			}
			else {  //MP�c�ʃ`�F�b�N�ɂЂ����������Ƃ��̏���
				printf("MP������Ȃ��I\n");
			}
		}
	}
}
/*int DisplayMenu(void)
* �퓬���[�h���̃R�}���h�I����ʂ�\��
* �߂�l�F�I�������R�}���h�̃��j���[�ԍ�(-1�̂݋����I���j
*/
int DisplayMenu(void) {
	char ch;
	while (1) {
		//�R�}���h���X�g�̕\��
		printf("----------\n�R�}���h��I��\n");
		printf("1.��������\n2.�X�L��\n3.�ڂ�����\n\n");
		//�L�[�{�[�h����ꕶ�����͂��ĕ����R�[�h���i�[
		ch = getch();
		//���͂��ꂽ���̂�'1'�`'3'�̊Ԃ������Ȃ�
		if (ch > '0' && ch < '4') {
			//�����R�[�h�𐮐��l�ɕϊ����ĕԂ�
			return ch - '0';
		}
		else if (ch == 'q') { //�B���R�}���h�F�����I��'q'
			//�����I������-1��Ԃ�
			return -1;
		}
	}
}
/*int SkillMenu(Chara c)
* �퓬���[�h���̃X�L���I����ʂ�\��
* ��1�����FChara�^�\���̕ϐ��i���L�����j
* �߂�l�F�I�������R�}���h�̃��j���[�ԍ� */
int SkillMenu(Chara c) {
	int ch, i;
	while (1) {
		//�X�L���ꗗ��Skill�^�\���̔z���name���g���ĕ\��
		printf("----------\n�X�L����I��\n");
		for (i = 0; i < Skil_Num; i++) {
			//�X�L���ԍ��͔z��̓Y�����{�P�̐��l
			printf("%d.%s\n", i + 1, c.skl[i].name);
		}
		printf("\n");
		//�L�[�{�[�h����ꕶ�����͂��āA�����l�ɕϊ�
		ch = getch() - '0';
		//�����l��1�`Skill_Numm�͈̔͂ł����
		if (ch > 0 && ch <= Skil_Num ) {
			//�����l-1��Ԃ��i�z��̓Y�����ԍ��ɂ��킹��j
			return ch - 1;
		}
	}
}

/*void DisplayStatus(Chara c)
* �퓬���[�h���̎��L�����̃X�e�[�^�X�\��
* ��1�����FChara�^�\���̕ϐ��i���L�����j*/
void DisplayStatus(Chara c) {
	printf("******************\n");
	//HP��4�����l�߁AMP��3�����l�߂ŕ\��
	printf("HP:%-4d  MP:%-3d\n", c.sp.hp, c.mp);
	//�t���O�������Ă���r�b�g�̊m�F
	if (c.sp.state) {
		printf("��ԁF ");
		if (c.sp.state & Poison)    { printf("�� "); }
		if (c.sp.state & Sleep)     { printf("���� "); }
		if (c.sp.state & Paralysis) { printf("��� "); }
		if (c.sp.state & Burn)      { printf("�Ώ� "); }
		if (c.sp.state & AtkUp)     { printf("�U���̓A�b�v "); }
		if (c.sp.state & AtkDown)   { printf("�U���̓_�E�� "); }
		if (c.sp.state & DefUp)     { printf("�h��̓A�b�v "); }
	}
	printf("\n******************\n");
}
int LoadDataFile(char* filename[], Chara* c, Mob* m) {
	FILE* fp;
	int i;
	//�f�[�^�t�@�C����File_Num����̂ŁAfor���ŌJ��Ԃ���������
	for (i = 0; i < File_Num; i++) {
		//filename��main�֐�����n���ꂽ�f�[�^�t�@�C���̃��X�g�i�z��j
		if (fp = fopen(filename[i], "r")) {
			//�f�[�^�̎�ނɂ���ď����𕪊�
			switch (i) {
			case 0:  //���L�����̃f�[�^�ǂݍ���
				//chara.csv�̏��ԁFname,hp,atk,def,state,maxhp,mp
				//%[^,]�́u,�v�̎�O�܂ł��ЂƂ̕�����Ƃ��ēǂݎ��
				//%u��unsigned int�̕ϊ��w��q
				//�����o���A�h���X�Ȃ灕�����Ȃ��A�ϐ��Ȃ灕������
				fscanf(fp, "%[^,],%d,%d,%d,%u,%d,%d",
					c->sp.name, &c->sp.hp, &c->sp.atk, &c->sp.def,
					&c->sp.state, &c->maxhp, &c->mp);
				break;
			case 1:  //�X�L���̃f�[�^�ǂݍ���
				for (int j = 0; j < Skil_Num; j++) {
					//skill.csv�̏��ԁFname,type,use_mp,effect
					fscanf(fp, "%[^,],%d,%d,%d\n",
						c->skl[j].name, &c->skl[j].type,
						&c->skl[j].use_mp, &c->skl[j].effect);
				}
				break;
			case 2:  //�G�L�����̃f�[�^�ǂݍ���
				for (int j = 0; j < Mob_Num; j++) {
					//mob.csv�̏��ԁFname,hp,atk,def,state,rate
					fscanf(fp, "%[^,],%d,%d,%d,%u,%d\n",
						(m + j)->sp.name, &(m + j)->sp.hp,
						&(m + j)->sp.atk, &(m + j)->sp.def,
						&(m + j)->sp.state, &(m + j)->rate);
					  //m�̓|�C���^�ϐ��Ȃ̂�mob�z��̊e�v�f��(m+j)�ij:0�`3�j�ƂȂ�
				}
				break;
			}
			//�J�����t�@�C�������
			fclose(fp);
		}
		else {  //fopen�Ɏ��s�����Ƃ��̏���
			printf("�t�@�C�����J���܂���!\n");
			//main�֐���-1��Ԃ�
			return -1;
		}
	}
	return 0;
}