#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
using namespace std;

constexpr int Skil_Num = 3;  //�X�L����
constexpr int Mob_Num = 3;   //�G�̐�
constexpr int File_Num = 3;  //�f�[�^�t�@�C����
//��������������UINT�ōĒ�`
//typedef unsigned int UINT;

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

//�o�߃^�[��(�����F���L�����U���^�[���A��F�G�L�����U���^�[��)
int TurnCount = 0;

class Battle {
public:
	Battle() = default;
	int Initialize() {
		//���L�����ƓG�L�����̃p�����[�^�ݒ�
		Chara chara;
		Mob mob[Mob_Num];
		//�g�p����f�[�^�t�@�C�����X�g
		string DataFile[] = { "chara.csv","skill.csv","mob.csv" };
		//�f�[�^�ǂݍ��݂̌��ʂ��i�[����ϐ���錾
		int result;
		//cout << "�t�@�C�����͊J�n" << endl;
		//LoadDataFile�֐��̌Ăяo���Ɩ߂�l�̊i�[
		result = LoadDataFile(DataFile, chara, mob);
		//�߂�l��-1�������Ƃ�
		if (result == -1) {
			cout << "�v���I�ȃG���[���������܂���\n";
			//main�֐���return���ŋ����I�ɏI������
			return 0;
		}
		//cout << "�t�@�C�����͊���" << endl;
		random_device rnd_dev{};
		mt19937 rand_engine(rnd_dev());
		uniform_int_distribution<int> mob_num(0, Mob_Num - 1);
		//������0~Mob_Num-1�̐��l�����߂�
		int num = mob_num(rand_engine);
		//cout << "������������" << endl;

		//�퓬���[�h���J�n
		BattleMode(chara, mob[num]);
		if (chara.sp.state & Dead) {
			cout << chara.sp.name << "�̎��S�ɂ��Q�[���I�[�o�[\n";
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
	void BattleMessage(Spec sp1, Spec& sp2) {
		//��_�����i�[����ϐ�
		int damage;
		//�^�[�����ЂƂi�߂Ă���
		TurnCount++;
		//�U������\��
		cout << sp1.name << "�̍U��\n";
		//�_���[�W�v�Z
		damage = DamageCalc(sp1, sp2);
		//��_���̕\��
		cout << sp2.name << "��" << damage << "�̃_���[�W\n\n";
		//�h�䑤����_���[�W����HP�����Z
		sp2.hp -= damage;
		//HP���O�ȉ��ɂȂ�����
		if (sp2.hp <= 0) {
			//�h�䑤���|���ꂽ�Ƃ������b�Z�[�W��\��
			cout << sp2.name << "�͓|���ꂽ\n";
			//�h�䑤�Ɏ��S�t���O�𗧂Ă�
			sp2.state |= Dead;
		}
	}
	/*void BattleMode(Chara* c, Mob m)
	* �퓬���[�h���̃��b�Z�[�W�\�����s��
	* ��1�����FChara�^�\���̕ϐ��̃A�h���X�i���L�����j
	* ��2�����FMob�^�\���̕ϐ��i�G�L�����j
	*/
	void BattleMode(Chara& c, Mob m) {
		constexpr double Poison_Damage = 0.8; //�ŏ�Ԃ̂Ƃ��̖��^�[��������
		constexpr double Burn_Damage = 0.9;   //�Ώ���Ԃ̂Ƃ��̖��^�[��������
		//	static const float Burn_Damage = 0.9;
		int command, skill;
		//system("cls");      //�R�}���h�v�����v�g��cls���߂̎��s
		DisplayStatus(c);
		cout << m.sp.name << "�������ꂽ�I\n";
		while (1) {
			command = DisplayMenu();

			//��Ԉُ�̂Ƃ���HP��MP�̏���
			if (c.sp.state & Poison) { //�ł̃t���O��ON�̂Ƃ� 
				c.sp.hp *= Poison_Damage;//���L����HP��Poison_Damage(0.8)�{�ɂ���
			}
			if (c.sp.state & Burn) {   //�Ώ��̃t���O��ON�̂Ƃ�
				c.sp.hp *= Burn_Damage;  //���L������HP��Burn_Damage(0.9)�{�ɂ���
				c.mp *= Burn_Damage;     //���L������MP��Burn_Damage(0.9)�{�ɂ���
			}
			//[��������]
			if (command == 1) {
				DisplayStatus(c);
				//TurnCount�������̂Ƃ��͎��L�����̍U��
				if (TurnCount % 2 == 0) {
					//�퓬���b�Z�[�W�̕\���Ɩh�䑤HP���Z�A���S�`�F�b�N
					BattleMessage(c.sp, m.sp);
					//�G�L�����̎��S�t���O��ON�Ȃ�
					if (m.sp.state & Dead) {
						break;
					}
				}
				//TurnCount����̂Ƃ��͓G�̍U��
				if (TurnCount % 2 == 1) {
					//�퓬���b�Z�[�W�̕\���Ɩh�䑤HP���Z�A���S�`�F�b�N
					BattleMessage(m.sp, c.sp);
					//���L�����̎��S�t���O��ON�Ȃ�
					if (c.sp.state & Dead) {
						break;
					}
					else { //���L����������ł��Ȃ���Έȉ��̏��������s
						//��Ԉُ�t���m���̌v�Z
						if (rand() % 100 < m.rate) {
							cout << "��Ԉُ�U�����󂯂��I\n";
							//���L�����ɏ�Ԉُ��t������Ƃ��ɂ́AAtk_Skill�t���O���������Ă���
							c.sp.state |= (m.sp.state & ~Atk_Skill);
						}
						DisplayStatus(c);
					}
				}
			}
			//DisplayMenu�ŋ����I���p�̃L�[�������ꂽ�Ƃ��̏���
			else if (command == -1) {
				c.sp.state |= Dead;  //���L�����̎��S�t���O��ON
				return;               //�֐��𔲂��o��
			}
			//[�X�L��]
			else if (command == 2) {
				cout << "�X�L���̑I��\n";
				skill = SkillMenu(c);  //skill��0~2�̂����ꂩ
				//MP�c�ʃ`�F�b�N�i��MP�ʂ��X�L���g�pMP�ʂ�葽���Ƃ��j
				if (c.mp >= c.skl[skill].use_mp) {
					//���L������MP���g�p�����Ԃ񌸂炷
					c.mp -= c.skl[skill].use_mp;
					//�X�L����type�l�ɂ���ĕ��򏈗�
					switch (c.skl[skill].type) {
					case 0:  //HP�񕜃X�L���g�p���̏���
						//���L����HP�ɃX�L���g�p�ɂ��񕜗�(effect�l�j�����Z
						c.sp.hp += c.skl[skill].effect;
						//���L����HP��MAXHP�𒴂�����AMAXHP�ɑ�����
						if (c.sp.hp > c.maxhp) { c.sp.hp = c.maxhp; }
						cout << "HP��" << c.skl[skill].effect << "�񕜂���!\n";
						break;
					case 1: //�U���̓A�b�v�̏���
						//���L����ATK��1.20�{�i��120��100�j
						c.sp.atk *= c.skl[skill].effect / 100.0;
						//�U���̓A�b�v�t���OON
						c.sp.state |= AtkUp;
						cout << "�U���͂��A�b�v����!\n";
						break;
					case 2: //��Ԉُ�񕜂̏���
						//�f�o�t�n����8�r�b�g������0�ɂ���r�b�g��(~DeBuff)��AND���Z
						c.sp.state &= ~DeBuff;
						cout << "��Ԉُ킪�񕜂���!\n";
						break;
					case 3:  //�h��̓A�b�v�̏���
						//���L������Def�l��1.5�{�i150��100.0�j�ɂ���
						c.sp.def *= c.skl[skill].effect / 100.0;
						//DefUp�t���O�𗧂Ă�
						c.sp.state |= DefUp;
						//�����A�b�v����������ʕ\��
						cout << "�h��͂��A�b�v�����I\n";
						break;
					default:
						break;
					}
					//���L�����̃X�e�[�^�X�̒l����ʕ\��
					DisplayStatus(c);
				}
				else {  //MP�c�ʃ`�F�b�N�ɂЂ����������Ƃ��̏���
					cout << "MP������Ȃ��I\n";
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
			cout << "----------\n�R�}���h��I��\n";
			cout << "1.��������\n2.�X�L��\n3.�ڂ�����\n\n";
			//�L�[�{�[�h����ꕶ�����͂��ĕ����R�[�h���i�[
			ch = getch();
			//���͂��ꂽ���̂�'1'�`'3'�̊Ԃ������Ȃ�
			if (ch > '0' && ch < '4') {
				//�����R�[�h�𐮐��l�ɕϊ����ĕԂ�
				return ch - '0';
			}
			else if (ch == 'q') { //�B���R�}���h�F�����I��'q'
				//�����I������-1��Ԃ�
				exit(-1);
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
			cout << "----------\n�X�L����I��\n";
			for (i = 0; i < Skil_Num; i++) {
				//�X�L���ԍ��͔z��̓Y�����{�P�̐��l
				cout << i + 1 << "." << c.skl[i].name << endl;
			}
			cout << endl;
			//�L�[�{�[�h����ꕶ�����͂��āA�����l�ɕϊ�
			ch = getch() - '0';
			//�����l��1�`Skill_Numm�͈̔͂ł����
			if (ch > 0 && ch <= Skil_Num) {
				//�����l-1��Ԃ��i�z��̓Y�����ԍ��ɂ��킹��j
				return ch - 1;
			}
		}
	}

	/*void DisplayStatus(Chara c)
	* �퓬���[�h���̎��L�����̃X�e�[�^�X�\��
	* ��1�����FChara�^�\���̕ϐ��i���L�����j*/
	void DisplayStatus(Chara c) {
		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), "#", 100, COORD{ 0,0 });
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,7 }
		);
		cout << "******************\n";
		//HP��5�����l�߁AMP��3�����l�߂ŕ\��
		cout << "HP:" << left << setw(5) << c.sp.hp
			<< "MP:" << right << setw(3) << c.mp << endl;
		//�t���O�������Ă���r�b�g�̊m�F
		if (c.sp.state) {
			cout << "��ԁF ";
			if (c.sp.state & Poison) { cout << "�� "; }
			if (c.sp.state & Sleeep) { cout << "���� "; }
			if (c.sp.state & Paralysis) { cout << "��� "; }
			if (c.sp.state & Burn) { cout << "�Ώ� "; }
			if (c.sp.state & AtkUp) { cout << "�U���̓A�b�v "; }
			if (c.sp.state & AtkDown) { cout << "�U���̓_�E�� "; }
			if (c.sp.state & DefUp) { cout << "�h��̓A�b�v "; }
		}
		cout << "******************\n";
	}
	int LoadDataFile(string filename[], Chara& c, Mob (&m)[Mob_Num]) {
		vector<string> v{};
		string text;
		ifstream fp;
		int i;
		//�f�[�^�t�@�C����File_Num����̂ŁAfor���ŌJ��Ԃ���������
		for (i = 0; i < File_Num; i++) {
			fp.open(filename[i]);
			//filename��main�֐�����n���ꂽ�f�[�^�t�@�C���̃��X�g�i�z��j
			if (fp) {
				//�f�[�^�̎�ނɂ���ď����𕪊�
				switch (i) {
				case 0:  //���L�����̃f�[�^�ǂݍ���
					while (getline(fp, text, ',')) {
						v.push_back(text);
					}
					c.sp.name = v[0];
					c.sp.hp = stoi(v[1]);
					c.sp.atk = stoi(v[2]);
					c.sp.def = stoi(v[3]);
					c.sp.state = stoi(v[4]);
					c.maxhp = stoi(v[5]);
					c.mp = stoi(v[6]);
					v.clear();
					break;
				case 1:  //�X�L���̃f�[�^�ǂݍ���
					for (int j = 0; j < Skil_Num; j++) {
						getline(fp, text);
						istringstream iss(text);
						while (getline(iss, text, ',')) {
							v.push_back(text);
						}
						c.skl[j].name = v[0];
						c.skl[j].type = stoi(v[1]);
						c.skl[j].use_mp = stoi(v[2]);
						c.skl[j].effect = stoi(v[3]);
						v.clear();
					}
					break;
				case 2:  //�G�L�����̃f�[�^�ǂݍ���
					for (int j = 0; j < Mob_Num; j++) {
						getline(fp, text);
						istringstream iss(text);
						while (getline(iss, text, ',')) {
							v.push_back(text);
						}
						m[j].sp.name = v[0];
						m[j].sp.hp = stoi(v[1]);
						m[j].sp.atk = stoi(v[2]);
						m[j].sp.def = stoi(v[3]);
						m[j].sp.state = stoi(v[4]);
						m[j].rate = stoi(v[5]);
						v.clear();
					}
					break;
				}
				//�J�����t�@�C�������
				fp.close();
			}
			else {  //fopen�Ɏ��s�����Ƃ��̏���
				cout << "�t�@�C�����J���܂���!\n";
				//main�֐���-1��Ԃ�
				return -1;
			}
		}
		return 0;
	}
};

int main() {
	Battle btl;
	btl.Initialize();
	return 0;
}