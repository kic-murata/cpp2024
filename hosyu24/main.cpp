/* このプログラムのソースコードは以下のURLで配布
https://bit.ly/4iffoE2
*/
#include<iostream>
#include<vector>
using namespace std;

//Parentクラスの定義
class Parent {
public:
	//コンストラクタ（コンストラクタとオーバー？？？）
	Parent() {};
	Parent(int age, double height, double weight, string name)
	:age(age), height(height), weight(weight), name(name) {};
	/* 引数ありのコンストラクタを使うことで、
	   イニシャライザによってメンバ変数を
		 コンストラクタの処理より前に初期化 */
	//？？？ラクタ
	~Parent() {};
	//？？関数
	virtual int getData() { return age; }
	//名前を取得するゲッター
	string getName() { return name; }
private:
	//年齢age・身長height・体重weight・名前name
	int age;
	double height;
	double weight;
	string name;
//public,private,protectedを？？？？指定子と呼ぶ
};

//Parentクラスを？？したChildクラスの定義　
class Child : public Parent {
public:
	//コンストラクタ
	Child() {};
	Child(int age, double height, double weight, string name)
		:Parent(age, height, weight, name) ,data(weight/(height*height)*10000) {};
	//デストラクタ
	~Child() {};
	//親クラスの関数のオーバー？？？
	int getData() { return data; }
private:
	int data;
};

//Familyクラスの定義
class Family {
public:
	//コンストラクタ
	Family() {};
	Family(vector<Child*> vec) { family_num = vec.size(); }
	//デストラクタ
	~Family() {};
	//ゲッター関数
	int getFamily() { return family_num; }
private:
	int family_num;
};

int main() {
	//Parentクラスのインスタンス生成
	Parent p(40, 173.2, 65.5, "太郎");
	cout << p.getName() << "の年齢は" << p.getData() << "歳" << endl;

	//Childクラスのインスタンス生成
	Child c(15, 160.8, 53.2, "一郎");
	cout << c.getName() << "のBMIは" << c.getData()  << endl;

	/* 可変長配列vectorの宣言
	 （格納できるのはChildクラスのインスタンスの？？？？）*/
	vector<Child*> vc{};
	//すでに生成したインスタンスの？？？？を配列末尾に追加
	vc.push_back(&c);
	//new演算子を使ってインスタンスを生成してその？？？？を配列末尾に追加
	vc.push_back(new Child(10, 142.5, 40.1, "次郎"));
	vc.push_back(new Child(8, 125.3, 32.6, "花子"));

	//？？for文を用いたループ処理
	for (auto c : vc) {
		//配列各要素は？？？？なので、メンバ関数を呼び出す際は？？？演算子を使用
		cout << "子供の名前は" << c->getName() << endl;
	}

	//Familyクラスのインスタンスを生成して初期値に配列vcを指定する
	Family f(vc);
	cout << "子供の人数は" << f.getFamily() << "人" << endl;

	return 0;
}