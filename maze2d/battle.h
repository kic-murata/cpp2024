#pragma once
#include <iostream>
using namespace std;

constexpr int Skil_Num = 3;  //�X�L����
constexpr int Mob_Num = 3;   //�G�̐�
constexpr int File_Num = 3;  //�f�[�^�t�@�C����

typedef struct { //Skill�^�\����
	string name; //�X�L����
	int type;      //�X�L���̎�ށi0: HP��, 1: AtkUp, 2: ��Ԉُ�񕜁j
	int use_mp;    //�g�pMP��
	int effect;    //�X�L������
} Skill;
typedef struct { //Spec�^�\����
	string name; //���O
	int hp;        //HP
	int atk;       //�U����
	int def;       //�h���
	int state;    //���
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
	Sleeep = 1 << 1,     //(  2)0000 0000 0000 0010(����)
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

class Battle {
public:
	Battle();
	int Initialize();
	int DamageCalc(Spec sp1, Spec sp2);
	void BattleMessage(Spec sp1, Spec& sp2);
	void BattleMode(Chara& c, Mob m);
	int DisplayMenu(void);
	int SkillMenu(Chara c);
	void DisplayStatus(Chara c);
	int LoadDataFile(string filename[], Chara& c, Mob(&m)[Mob_Num]);
	int SaveDataFile(string filename, const Chara& c);
};