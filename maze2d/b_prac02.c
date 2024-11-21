#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Skil_Num 4  //スキル数
#define Mob_Num 3   //敵の数
#define File_Num 3  //データファイル数
//符号無し整数をUINTで再定義
typedef unsigned int UINT;

typedef struct { //Skill型構造体
	char name[20]; //スキル名
	int type;      //スキルの種類（0: HP回復, 1: AtkUp, 2: 状態異常回復）
	int use_mp;    //使用MP量
	int effect;    //スキル効果
} Skill;
typedef struct { //Spec型構造体
	char name[20]; //名前
	int hp;        //HP
	int atk;       //攻撃力
	int def;       //防御力
	UINT state;    //状態
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
	Sleep = 1 << 1,      //(  2)0000 0000 0000 0010(睡眠)
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

//経過ターン(偶数：自キャラ攻撃ターン、奇数：敵キャラ攻撃ターン)
int TurnCount = 0;

//状態を表示する関数
void DisplayStatus(Chara c);

//戦闘モードへ移行する関数
void BattleMode(Chara* c, Mob m);
//戦闘時のメニュー表示を行う
int DisplayMenu(void);
//スキル使用時のメニュー表示を行う
int SkillMenu(Chara c);
//攻撃側と防御側のパラメータを使った攻撃ダメージ計算
int DamageCalc(Spec sp1, Spec sp2);
//戦闘モード時のHP計算と死亡判定
void BattleMessage(Spec sp1, Spec* sp2);
//データファイルを読み込んで値を設定する
int LoadDataFile(char* filename[], Chara* c, Mob* m);

/* b_prac01.exe [数字:0~Mob_Num-1]
* [数字:0~Mob_Num-1]は0からMob_Num-1までの数字を指定して実行することで
* 登場する敵の種類を指定できる。省略した場合は0~Mob_Num-1の乱数となる */
main(int argc, char* argv[])
{
	//乱数列（シード）の初期化
	srand(time(0));
	//自キャラと敵キャラのパラメータ設定
	Chara chara;
	Mob mob[Mob_Num];
	//使用するデータファイルリスト
	char* DataFile[] = { "chara.csv","skill.csv","mob.csv" };
	//データ読み込みの結果を格納する変数を宣言
	int result;
	//LoadDataFile関数の呼び出しと戻り値の格納
	result = LoadDataFile(DataFile, &chara, mob);
	//戻り値が-1だったとき
	if (result == -1) {
		printf("致命的なエラーが発生しました\n");
		//main関数をreturn文で強制的に終了する
		return;
	}

	//乱数で0~Mob_Num-1の数値を求める
	int num = rand() % Mob_Num;
	//実行時にコマンドライン引数があった場合
	if (argc > 1) {
		//引数を数値に変換
		num = atoi(argv[1]);
		//引数の数値が0~Mob_Num-1の範囲になければ
		if (num < 0 || num >= Mob_Num) {
			//乱数を生成
			num = rand() % Mob_Num;
		}
	}
	//戦闘モードを開始
	BattleMode(&chara, mob[num]);
	if (chara.sp.state & Dead) {
		printf("%sの死亡によりゲームオーバー\n", chara.sp.name);
	}
}
/*int DamageCalc(Spec sp1, Spec sp2)
* 与ダメ計算関数
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数（防御側）
* （与ダメ）＝攻撃側Atk×(攻撃側Atk÷防御側Def）＋攻撃側Atk×乱数0~0.5
*/
int DamageCalc(Spec sp1, Spec sp2) {
	int damage;
	//攻撃力ダウンフラグがONで、Atk_SkillがOFFのとき（自キャラのみこの条件に該当）
	if ((sp1.state & AtkDown) && !(sp1.state & Atk_Skill)) {
		//攻撃力を0.8倍にしてダメージ計算
		sp1.atk *= 0.8;
	}
	damage = sp1.atk * ((float)sp1.atk / sp2.def)
		+ sp1.atk * (rand() % 50) / 100.0;
	//100分の1の確率で会心/痛恨の一撃
	if (rand() % 100 == 99) {
		return 2 * damage;  //ダメージ量2倍
	}
	return damage;  //通常ダメージ
}
/*void BattleMessage(Spec sp1, Spec* sp2)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Spec型構造体変数（攻撃側）
* 第2引数：Spec型構造体変数のアドレス（防御側）
*/
void BattleMessage(Spec sp1, Spec* sp2) {
	//被ダメを格納する変数
	int damage;
	//ターンをひとつ進めておく
	TurnCount++;
	//攻撃側を表示
	printf("%sの攻撃\n", sp1.name);
	//ダメージ計算
	damage = DamageCalc(sp1, *sp2);
	//被ダメの表示
	printf("%sに%dのダメージ\n\n", sp2->name, damage);
	//防御側からダメージ分のHPを減算
	sp2->hp -= damage;
	//HPが０以下になったら
	if (sp2->hp <= 0) {
		//防御側が倒されたというメッセージを表示
		printf("%sは倒された\n", sp2->name);
		//防御側に死亡フラグを立てる
		sp2->state |= Dead;
	}
}
/*void BattleMode(Chara* c, Mob m)
* 戦闘モード時のメッセージ表示を行う
* 第1引数：Chara型構造体変数のアドレス（自キャラ）
* 第2引数：Mob型構造体変数（敵キャラ）
*/
void BattleMode(Chara* c, Mob m) {
#define Poison_Damage 0.8 //毒状態のときの毎ターン減少率
#define Burn_Damage 0.9   //火傷状態のときの毎ターン減少率
//	static const float Burn_Damage = 0.9;
	int command, skill;
	system("cls");      //コマンドプロンプトのcls命令の実行
	DisplayStatus(*c);
	printf("%sがあらわれた！\n", m.sp.name);
	while (1) {
		command = DisplayMenu();

		//状態異常のときのHPやMPの処理
		if (c->sp.state & Poison) { //毒のフラグがONのとき 
			c->sp.hp *= Poison_Damage;//自キャラHPをPoison_Damage(0.8)倍にする
		}
		if (c->sp.state & Burn) {   //火傷のフラグがONのとき
			c->sp.hp *= Burn_Damage;  //自キャラのHPをBurn_Damage(0.9)倍にして
			c->mp *= Burn_Damage;     //自キャラのMPもBurn_Damage(0.9)倍にする
		}
		//[たたかう]
		if (command == 1) {
			DisplayStatus(*c);
			//TurnCountが偶数のときは自キャラの攻撃
			if (TurnCount % 2 == 0) {
				//戦闘メッセージの表示と防御側HP減算、死亡チェック
				BattleMessage(c->sp, &m.sp);
				//敵キャラの死亡フラグがONなら
				if (m.sp.state & Dead) {
					break;
				}
			}
			//TurnCountが奇数のときは敵の攻撃
			if (TurnCount % 2 == 1) {
				//戦闘メッセージの表示と防御側HP減算、死亡チェック
				BattleMessage(m.sp, &c->sp);
				//自キャラの死亡フラグがONなら
				if (c->sp.state & Dead) {
					break;
				}
				else { //自キャラが死んでいなければ以下の処理を実行
					//状態異常付加確率の計算
					if (rand() % 100 < m.rate) {
						printf("状態異常攻撃を受けた！\n");
						//自キャラに状態異常を付加するときには、Atk_Skillフラグを除去しておく
						c->sp.state |= (m.sp.state & ~Atk_Skill);
					}
					DisplayStatus(*c);
				}
			}
		}
		//DisplayMenuで強制終了用のキーが押されたときの処理
		else if (command == -1) {
			c->sp.state |= Dead;  //自キャラの死亡フラグをON
			return;               //関数を抜け出る
		}
		//[スキル]
		else if (command == 2) {
			printf("スキルの選択\n");
			skill = SkillMenu(*c);  //skillは0~2のいずれか
			//MP残量チェック（自MP量がスキル使用MP量より多いとき）
			if (c->mp >= c->skl[skill].use_mp) {
				//自キャラのMPを使用したぶん減らす
				c->mp -= c->skl[skill].use_mp;
				//スキルのtype値によって分岐処理
				switch (c->skl[skill].type) {
				case 0:  //HP回復スキル使用時の処理
					//自キャラHPにスキル使用による回復量(effect値）を加算
					c->sp.hp += c->skl[skill].effect;
					//自キャラHPがMAXHPを超えたら、MAXHPに揃える
					if (c->sp.hp > c->maxhp) { c->sp.hp = c->maxhp; }
					printf("HPを%d回復した!\n", c->skl[skill].effect);
					break;
				case 1: //攻撃力アップの処理
					//自キャラATKを1.20倍（＝120÷100）
					c->sp.atk *= c->skl[skill].effect / 100.0;
					//攻撃力アップフラグON
					c->sp.state |= AtkUp;
					printf("攻撃力がアップした!\n");
					break;
				case 2: //状態異常回復の処理
					//デバフ系下位8ビットだけを0にするビット列(~DeBuff)をAND演算
					c->sp.state &= ~DeBuff;
					printf("状態異常が回復した!\n");
					break;
				case 3:  //防御力アップの処理
					//自キャラのDef値を1.5倍（150÷100.0）にする
					c->sp.def *= c->skl[skill].effect / 100.0;
					//DefUpフラグを立てる
					c->sp.state |= DefUp;
					//何がアップしたかを画面表示
					printf("防御力がアップした！\n");
					break;
				default:
					break;
				}
				//自キャラのステータスの値を画面表示
				DisplayStatus(*c);
			}
			else {  //MP残量チェックにひっかかったときの処理
				printf("MPが足りない！\n");
			}
		}
	}
}
/*int DisplayMenu(void)
* 戦闘モード時のコマンド選択画面を表示
* 戻り値：選択したコマンドのメニュー番号(-1のみ強制終了）
*/
int DisplayMenu(void) {
	char ch;
	while (1) {
		//コマンドリストの表示
		printf("----------\nコマンドを選択\n");
		printf("1.たたかう\n2.スキル\n3.ぼうぎょ\n\n");
		//キーボードから一文字入力して文字コードを格納
		ch = getch();
		//入力されたものが'1'～'3'の間も文字なら
		if (ch > '0' && ch < '4') {
			//文字コードを整数値に変換して返す
			return ch - '0';
		}
		else if (ch == 'q') { //隠しコマンド：強制終了'q'
			//強制終了時は-1を返す
			return -1;
		}
	}
}
/*int SkillMenu(Chara c)
* 戦闘モード時のスキル選択画面を表示
* 第1引数：Chara型構造体変数（自キャラ）
* 戻り値：選択したコマンドのメニュー番号 */
int SkillMenu(Chara c) {
	int ch, i;
	while (1) {
		//スキル一覧をSkill型構造体配列のnameを使って表示
		printf("----------\nスキルを選択\n");
		for (i = 0; i < Skil_Num; i++) {
			//スキル番号は配列の添え字＋１の数値
			printf("%d.%s\n", i + 1, c.skl[i].name);
		}
		printf("\n");
		//キーボードから一文字入力して、整数値に変換
		ch = getch() - '0';
		//整数値が1～Skill_Nummの範囲であれば
		if (ch > 0 && ch <= Skil_Num ) {
			//整数値-1を返す（配列の添え字番号にあわせる）
			return ch - 1;
		}
	}
}

/*void DisplayStatus(Chara c)
* 戦闘モード時の自キャラのステータス表示
* 第1引数：Chara型構造体変数（自キャラ）*/
void DisplayStatus(Chara c) {
	printf("******************\n");
	//HPを4桁左詰め、MPを3桁左詰めで表示
	printf("HP:%-4d  MP:%-3d\n", c.sp.hp, c.mp);
	//フラグが立っているビットの確認
	if (c.sp.state) {
		printf("状態： ");
		if (c.sp.state & Poison)    { printf("毒 "); }
		if (c.sp.state & Sleep)     { printf("睡眠 "); }
		if (c.sp.state & Paralysis) { printf("麻痺 "); }
		if (c.sp.state & Burn)      { printf("火傷 "); }
		if (c.sp.state & AtkUp)     { printf("攻撃力アップ "); }
		if (c.sp.state & AtkDown)   { printf("攻撃力ダウン "); }
		if (c.sp.state & DefUp)     { printf("防御力アップ "); }
	}
	printf("\n******************\n");
}
int LoadDataFile(char* filename[], Chara* c, Mob* m) {
	FILE* fp;
	int i;
	//データファイルはFile_Num個あるので、for文で繰り返し処理する
	for (i = 0; i < File_Num; i++) {
		//filenameはmain関数から渡されたデータファイルのリスト（配列）
		if (fp = fopen(filename[i], "r")) {
			//データの種類によって処理を分岐
			switch (i) {
			case 0:  //自キャラのデータ読み込み
				//chara.csvの順番：name,hp,atk,def,state,maxhp,mp
				//%[^,]は「,」の手前までをひとつの文字列として読み取る
				//%uはunsigned intの変換指定子
				//メンバがアドレスなら＆をつけない、変数なら＆をつける
				fscanf(fp, "%[^,],%d,%d,%d,%u,%d,%d",
					c->sp.name, &c->sp.hp, &c->sp.atk, &c->sp.def,
					&c->sp.state, &c->maxhp, &c->mp);
				break;
			case 1:  //スキルのデータ読み込み
				for (int j = 0; j < Skil_Num; j++) {
					//skill.csvの順番：name,type,use_mp,effect
					fscanf(fp, "%[^,],%d,%d,%d\n",
						c->skl[j].name, &c->skl[j].type,
						&c->skl[j].use_mp, &c->skl[j].effect);
				}
				break;
			case 2:  //敵キャラのデータ読み込み
				for (int j = 0; j < Mob_Num; j++) {
					//mob.csvの順番：name,hp,atk,def,state,rate
					fscanf(fp, "%[^,],%d,%d,%d,%u,%d\n",
						(m + j)->sp.name, &(m + j)->sp.hp,
						&(m + j)->sp.atk, &(m + j)->sp.def,
						&(m + j)->sp.state, &(m + j)->rate);
					  //mはポインタ変数なのでmob配列の各要素は(m+j)（j:0～3）となる
				}
				break;
			}
			//開いたファイルを閉じる
			fclose(fp);
		}
		else {  //fopenに失敗したときの処理
			printf("ファイルを開けません!\n");
			//main関数に-1を返す
			return -1;
		}
	}
	return 0;
}