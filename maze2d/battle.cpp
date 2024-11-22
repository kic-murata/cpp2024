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

constexpr int Skil_Num = 3;  //スキル数
constexpr int Mob_Num = 3;   //敵の数
constexpr int File_Num = 3;  //データファイル数
//符号無し整数をUINTで再定義
//typedef unsigned int UINT;

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

//経過ターン(偶数：自キャラ攻撃ターン、奇数：敵キャラ攻撃ターン)
int TurnCount = 0;

class Battle {
public:
	Battle() = default;
	int Initialize() {
		//自キャラと敵キャラのパラメータ設定
		Chara chara;
		Mob mob[Mob_Num];
		//使用するデータファイルリスト
		string DataFile[] = { "chara.csv","skill.csv","mob.csv" };
		//データ読み込みの結果を格納する変数を宣言
		int result;
		//cout << "ファイル入力開始" << endl;
		//LoadDataFile関数の呼び出しと戻り値の格納
		result = LoadDataFile(DataFile, chara, mob);
		//戻り値が-1だったとき
		if (result == -1) {
			cout << "致命的なエラーが発生しました\n";
			//main関数をreturn文で強制的に終了する
			return 0;
		}
		//cout << "ファイル入力完了" << endl;
		random_device rnd_dev{};
		mt19937 rand_engine(rnd_dev());
		uniform_int_distribution<int> mob_num(0, Mob_Num - 1);
		//乱数で0~Mob_Num-1の数値を求める
		int num = mob_num(rand_engine);
		//cout << "乱数生成完了" << endl;

		//戦闘モードを開始
		BattleMode(chara, mob[num]);
		if (chara.sp.state & Dead) {
			cout << chara.sp.name << "の死亡によりゲームオーバー\n";
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
	void BattleMessage(Spec sp1, Spec& sp2) {
		//被ダメを格納する変数
		int damage;
		//ターンをひとつ進めておく
		TurnCount++;
		//攻撃側を表示
		cout << sp1.name << "の攻撃\n";
		//ダメージ計算
		damage = DamageCalc(sp1, sp2);
		//被ダメの表示
		cout << sp2.name << "に" << damage << "のダメージ\n\n";
		//防御側からダメージ分のHPを減算
		sp2.hp -= damage;
		//HPが０以下になったら
		if (sp2.hp <= 0) {
			//防御側が倒されたというメッセージを表示
			cout << sp2.name << "は倒された\n";
			//防御側に死亡フラグを立てる
			sp2.state |= Dead;
		}
	}
	/*void BattleMode(Chara* c, Mob m)
	* 戦闘モード時のメッセージ表示を行う
	* 第1引数：Chara型構造体変数のアドレス（自キャラ）
	* 第2引数：Mob型構造体変数（敵キャラ）
	*/
	void BattleMode(Chara& c, Mob m) {
		constexpr double Poison_Damage = 0.8; //毒状態のときの毎ターン減少率
		constexpr double Burn_Damage = 0.9;   //火傷状態のときの毎ターン減少率
		//	static const float Burn_Damage = 0.9;
		int command, skill;
		//system("cls");      //コマンドプロンプトのcls命令の実行
		DisplayStatus(c);
		cout << m.sp.name << "があらわれた！\n";
		while (1) {
			command = DisplayMenu();

			//状態異常のときのHPやMPの処理
			if (c.sp.state & Poison) { //毒のフラグがONのとき 
				c.sp.hp *= Poison_Damage;//自キャラHPをPoison_Damage(0.8)倍にする
			}
			if (c.sp.state & Burn) {   //火傷のフラグがONのとき
				c.sp.hp *= Burn_Damage;  //自キャラのHPをBurn_Damage(0.9)倍にして
				c.mp *= Burn_Damage;     //自キャラのMPもBurn_Damage(0.9)倍にする
			}
			//[たたかう]
			if (command == 1) {
				DisplayStatus(c);
				//TurnCountが偶数のときは自キャラの攻撃
				if (TurnCount % 2 == 0) {
					//戦闘メッセージの表示と防御側HP減算、死亡チェック
					BattleMessage(c.sp, m.sp);
					//敵キャラの死亡フラグがONなら
					if (m.sp.state & Dead) {
						break;
					}
				}
				//TurnCountが奇数のときは敵の攻撃
				if (TurnCount % 2 == 1) {
					//戦闘メッセージの表示と防御側HP減算、死亡チェック
					BattleMessage(m.sp, c.sp);
					//自キャラの死亡フラグがONなら
					if (c.sp.state & Dead) {
						break;
					}
					else { //自キャラが死んでいなければ以下の処理を実行
						//状態異常付加確率の計算
						if (rand() % 100 < m.rate) {
							cout << "状態異常攻撃を受けた！\n";
							//自キャラに状態異常を付加するときには、Atk_Skillフラグを除去しておく
							c.sp.state |= (m.sp.state & ~Atk_Skill);
						}
						DisplayStatus(c);
					}
				}
			}
			//DisplayMenuで強制終了用のキーが押されたときの処理
			else if (command == -1) {
				c.sp.state |= Dead;  //自キャラの死亡フラグをON
				return;               //関数を抜け出る
			}
			//[スキル]
			else if (command == 2) {
				cout << "スキルの選択\n";
				skill = SkillMenu(c);  //skillは0~2のいずれか
				//MP残量チェック（自MP量がスキル使用MP量より多いとき）
				if (c.mp >= c.skl[skill].use_mp) {
					//自キャラのMPを使用したぶん減らす
					c.mp -= c.skl[skill].use_mp;
					//スキルのtype値によって分岐処理
					switch (c.skl[skill].type) {
					case 0:  //HP回復スキル使用時の処理
						//自キャラHPにスキル使用による回復量(effect値）を加算
						c.sp.hp += c.skl[skill].effect;
						//自キャラHPがMAXHPを超えたら、MAXHPに揃える
						if (c.sp.hp > c.maxhp) { c.sp.hp = c.maxhp; }
						cout << "HPを" << c.skl[skill].effect << "回復した!\n";
						break;
					case 1: //攻撃力アップの処理
						//自キャラATKを1.20倍（＝120÷100）
						c.sp.atk *= c.skl[skill].effect / 100.0;
						//攻撃力アップフラグON
						c.sp.state |= AtkUp;
						cout << "攻撃力がアップした!\n";
						break;
					case 2: //状態異常回復の処理
						//デバフ系下位8ビットだけを0にするビット列(~DeBuff)をAND演算
						c.sp.state &= ~DeBuff;
						cout << "状態異常が回復した!\n";
						break;
					case 3:  //防御力アップの処理
						//自キャラのDef値を1.5倍（150÷100.0）にする
						c.sp.def *= c.skl[skill].effect / 100.0;
						//DefUpフラグを立てる
						c.sp.state |= DefUp;
						//何がアップしたかを画面表示
						cout << "防御力がアップした！\n";
						break;
					default:
						break;
					}
					//自キャラのステータスの値を画面表示
					DisplayStatus(c);
				}
				else {  //MP残量チェックにひっかかったときの処理
					cout << "MPが足りない！\n";
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
			cout << "----------\nコマンドを選択\n";
			cout << "1.たたかう\n2.スキル\n3.ぼうぎょ\n\n";
			//キーボードから一文字入力して文字コードを格納
			ch = getch();
			//入力されたものが'1'～'3'の間も文字なら
			if (ch > '0' && ch < '4') {
				//文字コードを整数値に変換して返す
				return ch - '0';
			}
			else if (ch == 'q') { //隠しコマンド：強制終了'q'
				//強制終了時は-1を返す
				exit(-1);
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
			cout << "----------\nスキルを選択\n";
			for (i = 0; i < Skil_Num; i++) {
				//スキル番号は配列の添え字＋１の数値
				cout << i + 1 << "." << c.skl[i].name << endl;
			}
			cout << endl;
			//キーボードから一文字入力して、整数値に変換
			ch = getch() - '0';
			//整数値が1～Skill_Nummの範囲であれば
			if (ch > 0 && ch <= Skil_Num) {
				//整数値-1を返す（配列の添え字番号にあわせる）
				return ch - 1;
			}
		}
	}

	/*void DisplayStatus(Chara c)
	* 戦闘モード時の自キャラのステータス表示
	* 第1引数：Chara型構造体変数（自キャラ）*/
	void DisplayStatus(Chara c) {
		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), "#", 100, COORD{ 0,0 });
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,7 }
		);
		cout << "******************\n";
		//HPを5桁左詰め、MPを3桁左詰めで表示
		cout << "HP:" << left << setw(5) << c.sp.hp
			<< "MP:" << right << setw(3) << c.mp << endl;
		//フラグが立っているビットの確認
		if (c.sp.state) {
			cout << "状態： ";
			if (c.sp.state & Poison) { cout << "毒 "; }
			if (c.sp.state & Sleeep) { cout << "睡眠 "; }
			if (c.sp.state & Paralysis) { cout << "麻痺 "; }
			if (c.sp.state & Burn) { cout << "火傷 "; }
			if (c.sp.state & AtkUp) { cout << "攻撃力アップ "; }
			if (c.sp.state & AtkDown) { cout << "攻撃力ダウン "; }
			if (c.sp.state & DefUp) { cout << "防御力アップ "; }
		}
		cout << "******************\n";
	}
	int LoadDataFile(string filename[], Chara& c, Mob (&m)[Mob_Num]) {
		vector<string> v{};
		string text;
		ifstream fp;
		int i;
		//データファイルはFile_Num個あるので、for文で繰り返し処理する
		for (i = 0; i < File_Num; i++) {
			fp.open(filename[i]);
			//filenameはmain関数から渡されたデータファイルのリスト（配列）
			if (fp) {
				//データの種類によって処理を分岐
				switch (i) {
				case 0:  //自キャラのデータ読み込み
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
				case 1:  //スキルのデータ読み込み
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
				case 2:  //敵キャラのデータ読み込み
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
				//開いたファイルを閉じる
				fp.close();
			}
			else {  //fopenに失敗したときの処理
				cout << "ファイルを開けません!\n";
				//main関数に-1を返す
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