#pragma once
#include <iostream>
using namespace std;

constexpr int Skil_Num = 3;  //スキル数
constexpr int Mob_Num = 3;   //敵の数
constexpr int File_Num = 3;  //データファイル数

typedef struct { //Skill型構造体
	string name; //スキル名
	int type;      //スキルの種類（0: HP回復, 1: AtkUp, 2: 状態異常回復）
	int use_mp;    //使用MP量
	int effect;    //スキル効果
} Skill;
typedef struct { //Spec型構造体
	string name; //名前
	int hp;        //HP
	int atk;       //攻撃力
	int def;       //防御力
	int state;    //状態
} Spec;
typedef struct { //Chara型構造体
	Spec sp;       //Spec型構造体変数
	int maxhp;     //最大HP
	int mp;        //MP
	Skill skl[Skil_Num]; //Skill型構造体配列
} Chara;
typedef struct { //Mob型構造体
	Spec sp;       //Spec型構造体変数
	int rate;      //状態異常攻撃発生レート%表記
} Mob;

//列挙型BitStateの宣言
enum BitState
{
	//通常状態
	Base = 0,            //0000 0000 0000 0000
	//(1からいくつ左にシフトするか)
	Poison = 1 << 0,     //(  1)0000 0000 0000 0001(毒)
	Sleeep = 1 << 1,     //(  2)0000 0000 0000 0010(睡眠)
	Paralysis = 1 << 2,  //(  4)0000 0000 0000 0100(麻痺)
	Burn = 1 << 3,       //(  8)0000 0000 0000 1000(火傷)Up)
	AtkDown = 1 << 5,    //( 32)0000 0000 0010 0000(攻撃力Down)
	Dead = 1 << 6,       //( 64)0000 0000 0100 0000(死亡フラグ)
  Atk_Skill = 1 << 7,  //(128)0000 0000 1000 0000
                       //(このフラグがONのみ状態異常を付加可能）
	AtkUp = 1 << 8,      //0000 0001 0000 0000(攻撃力Up)
	DefUp = 1 << 9,      //0000 0010 0000 0000(防御力Up）
	DeBuff = 0xff        //0000 0000 1111 1111(デバフ解除用)
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